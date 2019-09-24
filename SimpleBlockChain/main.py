from json import JSONEncoder, JSONDecoder
from timeit import default_timer as timer
from datetime import timedelta, datetime, time
from collections import namedtuple

import random
import codecs
import hashlib
import json


def pair_hash(hash1, hash2):
    a1 = codecs.decode(hash1, "hex")[::-1]
    b1 = codecs.decode(hash2, "hex")[::-1]

    h = hashlib.sha256(hashlib.sha256(a1 + b1).digest()).digest()
    return str(codecs.encode(h[::-1], 'hex'), 'ascii')


class Encoder(JSONEncoder):
    def default(self, o):
        if isinstance(o, datetime):
            return str(o)
        else:
            return o.__dict__


class Transaction:
    def __init__(self, sender, receiver, amount):
        self.sender = sender
        self.receiver = receiver
        self.amount = amount

        key = (self.sender + self.receiver + str(self.amount) + str(random.random())).encode()
        self.hash = hashlib.sha256(key).hexdigest()

    def getHash(self):
        return self.hash


class Block:
    def __init__(self, ind, prev_hash):
        self.ind = ind
        self.prev_hash = prev_hash
        self.timestamp = datetime.now()
        self.list_of_transactions = []
        self.finalized = False

    def add_transaction(self, transaction):
        self.list_of_transactions.append(transaction)
        return self

    def finalize(self):
        hash_list = [t.getHash() for t in self.list_of_transactions]
        self.merkle_root = self.get_merkle_root(hash_list)

        hash = self.proof_of_work()
        self.finalized = True
        return self

    def proof_of_work(self):
        difficulty = 3

        nonce = 0  # random.randint(1, 1000000)
        while True:
            guess = (self.merkle_root + self.prev_hash + str(nonce)).encode()
            guess_hash = hashlib.sha256(guess).hexdigest()
            if guess_hash[:difficulty] == '0' * difficulty:
                self.nonce = nonce
                self.hash = guess_hash
                break
            nonce += 1

    @staticmethod
    def get_merkle_root(hash_list):
        if len(hash_list) == 1:
            return hash_list[0]

        new_hashes = []
        if len(hash_list) % 2 == 1:
            hash_list.append(hash_list[-1])

        for i in range(1, len(hash_list), 2):
            new_hashes.append(pair_hash(hash_list[i - 1], hash_list[i]))

        return Block.get_merkle_root(new_hashes)

    @staticmethod
    def get_genesis_block_hash():
        return "0" * 10


def flatten_hook(obj):
    for key, value in obj.iteritems():
        obj[key] = json.loads(value, object_hook=flatten_hook)
    return obj


class BlockChain:
    def __init__(self):
        self.list_of_blocks = []
        self.wallet = {"Alice": 50}

    def save(self, file):
        content = json.dumps(self.__dict__, indent=4, cls=Encoder)
        # print(content)
        file.write(content)

    def load(self, file):
        self.__dict__ = json.loads(file.read())
        for i in range(len(self.list_of_blocks)):
            block = self.list_of_blocks[i]
            self.list_of_blocks[i] = namedtuple("Block", block.keys())(*block.values())
            for j in range(len(self.list_of_blocks[i].list_of_transactions)):
                transaction = self.list_of_blocks[i].list_of_transactions[j]
                self.list_of_blocks[i].list_of_transactions[j] = \
                    namedtuple("Transaction", transaction.keys())(*transaction.values())
        return self

    def addBlock(self, b):
        self.list_of_blocks.append(b)
        # apply transactions
        print("-" * 80)
        for t in b.list_of_transactions:
            if t.sender not in self.wallet:
                self.wallet[t.sender] = 0
            if t.receiver not in self.wallet:
                self.wallet[t.receiver] = 0

            if self.wallet[t.sender] >= t.amount or t.sender == t.receiver:
                self.wallet[t.sender] -= t.amount
                self.wallet[t.receiver] += t.amount
                print("Applying transaction from {} to {} with {} coin(s)".format(t.sender, t.receiver, t.amount))
            else:
                print("Skipping transaction from {} to {} with {} coin(s)".format(t.sender, t.receiver, t.amount))
        print("*" * 20)
        print("Balance after block:")
        for key, obj in self.wallet.items():
            print(key, obj)
        print("*" * 20)
        return self

    def check_correctness(self):
        for ind, block in enumerate(self.list_of_blocks):
            hash_list = [t.hash for t in block.list_of_transactions]
            if Block.get_merkle_root(hash_list) != block.merkle_root:
                print('Transaction list of block {} is corrupted'.format(ind))

        for i in range(1, len(self.list_of_blocks)):
            if self.list_of_blocks[i - 1].hash != self.list_of_blocks[i].prev_hash:
                print('Block {} has incorrect prev_hash'.format(i))

    def search_transactions(self, min_amount):
        for block in self.list_of_blocks:
            for transaction in block.list_of_transactions:
                if transaction.amount > min_amount:
                    print("Found transaction in block {} from {} to {} with amount {}".format(
                        block.ind, transaction.sender, transaction.receiver, transaction.amount))

    def getBalance(self, wallet_name):
        if wallet_name in self.wallet:
            print("Current balance of user {} is: {}".format(wallet_name, self.wallet[wallet_name]))
        else:
            print("No such user in blockchain")


def load_scenario():
    f2 = open("test.json", "r")
    b = BlockChain()
    b.load(f2)
    b.check_correctness()


def save_scenario():
    blockChain = BlockChain()

    b = Block(1, Block.get_genesis_block_hash())
    b.add_transaction(Transaction("Alice", "Bob", 13))
    b.add_transaction(Transaction("Bob", "Alice", 8))
    b.finalize()
    blockChain.addBlock(b)

    blockChain.getBalance("Alice")

    c = Block(2, b.hash)
    c.add_transaction(Transaction("Bob", "Eva", 2))
    c.add_transaction(Transaction("Alice", "Eva", 10))
    c.finalize()
    blockChain.addBlock(c)

    print('*' * 60)
    print("Search transactions")
    blockChain.search_transactions(min_amount=10)
    f = open("test.json", "w")
    blockChain.save(f)
    f.close()


if __name__ == "__main__":
    # save_scenario()
    load_scenario()
