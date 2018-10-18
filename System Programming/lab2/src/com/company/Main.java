package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Array;
import java.util.*;

public class Main {
    private static DFA readDFA(String filePath) throws FileNotFoundException {
        DFA.Builder builder = new DFA.Builder();
        Scanner s = new Scanner(new File(filePath));
        int alphabetSize = s.nextInt();
        ArrayList<String> alphabetList = new ArrayList<>();
        for (int i = 0; i < alphabetSize ; i++)
            alphabetList.add(s.next());

        builder.setStartState(s.next());
        int finalStatesSize = s.nextInt();
        ArrayList<String> finalStatesList = new ArrayList<>();
        for (int i = 0; i < finalStatesSize ; i++)
            finalStatesList.add(s.next());

        builder.setFinalStates(new HashSet<>(finalStatesList));
        builder.setAlphabet(new HashSet<>(alphabetList));
        builder.createTransitions();
        while (s.hasNext()) {
            builder.addTransition(s.next(), s.next(), s.next());
        }
        return builder.build();
    }

    public static void main(String[] args) throws FileNotFoundException {
        DFA dfa = new DFA.Builder()
                .setAlphabet(new HashSet<>(Arrays.asList("0", "1", "2", "3")))
                .setStartState("0")
                .setFinalStates(new HashSet<>(Arrays.asList("1")))
                .createTransitions()
                .addTransition("0", "a", "1")
                .addTransition("1", "a", "2")
                .addTransition("1", "b", "3")
                .addTransition("2", "a", "3")
                .build();

        dfa = new DFA.Builder()
                .setAlphabet(new HashSet<>(Arrays.asList("0", "1")))
                .setStartState("a")
                .setFinalStates(new HashSet<>(Arrays.asList("d", "c", "e")))
                .createTransitions()
                .addTransition("a", "0", "b")
                .addTransition("a", "1", "c")
                .addTransition("b", "0", "a")
                .addTransition("b", "1", "d")
                .addTransition("c", "0", "e")
                .addTransition("c", "1", "f")
                .addTransition("d", "0", "e")
                .addTransition("d", "1", "f")
                .addTransition("e", "0", "e")
                .addTransition("e", "1", "f")
                .addTransition("f", "0", "f")
                .addTransition("f", "1", "f")
                .build();

        dfa = readDFA("DFATest2.txt");
        dfa.print();

        dfa.runMinimization();

        dfa.print();
    }
}
