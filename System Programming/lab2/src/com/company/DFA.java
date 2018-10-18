package com.company;

import org.jetbrains.annotations.NotNull;

import java.util.*;

public class DFA {
    private final Set<String> alphabet;
    private final String startState;
    private final Set<String> finalStates;
    private Map<String, Map<String, String>> transitions;


    public DFA(Set<String> alphabet, String startState, Set<String> finalStates, Map<String, Map<String, String>> transitions) {
        this.alphabet = alphabet;
        this.startState = startState;
        this.finalStates = finalStates;
        this.transitions = transitions;
    }

    public void print() {
        System.out.println(alphabet);
        System.out.println(finalStates);
        for (Map.Entry<String, Map<String, String>> states : transitions.entrySet()) {
            for(Map.Entry<String, String> state : states.getValue().entrySet()){
                System.out.print(states.getKey());
                System.out.print(" ");
                System.out.print(state.getKey());
                System.out.print(" ");
                System.out.print(state.getValue());
                System.out.print("\n");
            }
//            System.out.print(states.getKey());
//            System.out.print(" -> ");
//            System.out.print(states.getValue());
//            System.out.print('\n');
        }
    }


    private boolean dfsFinite(String currentState, Set<String> finiteStates, Set<String> visitedStates) {

        if (visitedStates.contains(currentState)) {
            return finiteStates.contains(currentState);
        }

        visitedStates.add(currentState);
        boolean leadToFiniteState = finiteStates.contains(currentState);
        if (transitions.containsKey(currentState)) {
            for (Map.Entry<String, String> nextState : transitions.get(currentState).entrySet()) {
                leadToFiniteState |= dfsFinite(nextState.getValue(), finiteStates, visitedStates);
            }
        }
        if (leadToFiniteState) {
            finiteStates.add(currentState);
        }
        return leadToFiniteState;
    }

    private void dfsReach(String currentState, Set<String> reachableStates) {
        if (reachableStates.contains(currentState)) {
            return;
        }
        reachableStates.add(currentState);
        if (transitions.containsKey(currentState)) {
            for (Map.Entry<String, String> nextState : transitions.get(currentState).entrySet()) {
                dfsReach(nextState.getValue(), reachableStates);
            }
        }
    }

    private void removeRedundantStates() {
        Set<String> reachableStates = new HashSet<>();
        Set<String> visitedStates = new HashSet<>();
        Set<String> finiteStates = new HashSet<>(finalStates);

        dfsReach(startState, reachableStates);

        for (String currentState : transitions.keySet()) {
            dfsFinite(currentState, finiteStates, visitedStates);
        }

        reachableStates.retainAll(finiteStates);
        transitions.keySet().retainAll(reachableStates);
        for (Map<String, String> nextState : transitions.values()) {
            nextState.values().retainAll(reachableStates);
        }
    }

    private void mergeStates(@NotNull Set<Set<String>> statesSet) {
        Map<String, String> representer = new HashMap<>();
        for (Set<String> subSet : statesSet) {
            String first = Collections.min(subSet);
            for (String entry : subSet) {
                representer.put(entry, first);
            }
        }
        for(Map.Entry<String, String> entry:representer.entrySet()){
            // output edges
            String classKey =  entry.getKey();
            String classValue = entry.getValue();
            if(!classKey.equals(classValue)) {
                if (transitions.containsKey(classValue) && transitions.containsKey(classKey)) {
                    Map<String, String> q = transitions.get(classValue);
                    q.putAll(transitions.get(classKey));
                    transitions.remove(classKey);
                }
            }
            // input edges
        }
        for(Map.Entry<String, Map<String, String >> x:transitions.entrySet()){
            Map<String, String> inner = x.getValue();
            for(Map.Entry<String, String> s:inner.entrySet()){
                String q = s.getValue();
                if(representer.containsKey(q)){
                    inner.replace(s.getKey(), representer.get(q));
                }
            }
        }

    }

    private Set<Set<String>> findEquivalenceClasses() {
        Set<Set<String>> partitions = new HashSet<>();

        Set<String> nonFinalStates = new HashSet<>(transitions.keySet());
        nonFinalStates.removeAll(finalStates);

        partitions.add(nonFinalStates);
        partitions.add(new HashSet<>(finalStates));

        LinkedHashSet<Set<String>> queue = new LinkedHashSet<>();
        queue.add(finalStates);

        while (!queue.isEmpty()) {
            Set<String> currState = new HashSet<String>(queue.iterator().next());
            queue.remove(queue.iterator().next());

            for (String rule : alphabet) {
                Set<String> X = split(rule, currState);
                Set<Set<String>> partitionsToRemove = new HashSet<>();
                Set<Set<String>> partitionsToAdd = new HashSet<>();

                for (Set<String> Y : partitions) {
                    Set<String> intersection = new HashSet<>(X);
                    intersection.retainAll(Y);

                    Set<String> difference = new HashSet<>(Y);
                    difference.removeAll(X);

                    if (!intersection.isEmpty() && !difference.isEmpty()) {
                        partitionsToRemove.add(Y);
                        partitionsToAdd.add(difference);
                        partitionsToAdd.add(intersection);

                        if (queue.contains(Y)) {
                            queue.remove(Y);
                            queue.add(difference);
                            queue.add(intersection);
                        } else {
                            if (intersection.size() <= difference.size()) {
                                queue.add(intersection);
                            } else {
                                queue.add(difference);
                            }
                        }
                    }
                }
                partitions.addAll(partitionsToAdd);
                partitions.removeAll(partitionsToRemove);
            }
        }
        return partitions;
    }

    private Set<String> split(String rule, Set<String> A) {
        Set<String> X = new HashSet<>();
        for (Map.Entry<String, Map<String, String>> state : transitions.entrySet()) {
            String nextState = state.getValue().get(rule);
            if (nextState != null && A.contains(nextState)) {
                X.add(state.getKey());
            }
        }
        return X;
    }


    public void runMinimization() {
        removeRedundantStates();
        Set<Set<String>> classes = findEquivalenceClasses();
        System.out.println(classes);
        System.out.println(transitions);
        mergeStates(classes);
        System.out.println(transitions);
    }

    public static class Builder {
        private Set<String> alphabet;
        private String startState;
        private Set<String> finalStates;
        private Map<String, Map<String, String>> transitions;

        public Builder setAlphabet(Set<String> alphabet) {
            this.alphabet = alphabet;
            return this;
        }

        public Builder setStartState(String startState) {
            this.startState = startState;
            return this;
        }

        public Builder setFinalStates(Set<String> finalStates) {
            this.finalStates = finalStates;
            return this;
        }

        public Builder createTransitions() {
            this.transitions = new HashMap<>();
            return this;
        }

        public Builder addTransition(String startState, String rule, String finalState) {
            if (!transitions.containsKey(startState))
                transitions.put(startState, new HashMap<>());
            transitions.get(startState).put(rule, finalState);
            return this;
        }

        public DFA build() {
            return new DFA(alphabet, startState, finalStates, transitions);
        }

    }
}
