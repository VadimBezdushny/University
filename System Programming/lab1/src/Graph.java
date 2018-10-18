import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class Graph {
    private ArrayList<String> Nodes;
    private int N;
    private int[][] distanceMatrix;
    private int[][] adjacencyMatrix;

    Graph(ArrayList<String> words) {
        N = words.size();
        Nodes = words;
    }

    private void calculateDistanceMatrix() {
        distanceMatrix = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                distanceMatrix[j][i] = distanceMatrix[i][j] = wordsDistance(Nodes.get(i), Nodes.get(j));
            }
        }
    }

    private void calculateAdjacencyMatrix() {
        adjacencyMatrix = new int[N][N];
        int maxDistance = 0;
        for (int i = 0; i < N; i++) {
            maxDistance = Math.max(maxDistance, Arrays.stream(distanceMatrix[i]).max().getAsInt());
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j || distanceMatrix[i][j] == maxDistance) {
                    adjacencyMatrix[i][j] = 1;
                }
            }
        }
    }

    private boolean checkMaskCorectness(ArrayList<Integer> maskIndices) {
        for (int i : maskIndices)
            for (int j : maskIndices)
                if (adjacencyMatrix[i][j] == 0)
                    return false;

        return true;
    }

    private boolean checkMaskCompleteness(ArrayList<Integer> maskIndices) {
        if (maskIndices.isEmpty()) return true;
        for (int any_iter = 0; any_iter < N; any_iter++) {
            if (Collections.binarySearch(maskIndices, any_iter) < 0) {
                // if element is not in mask
                boolean conflict_node_exists = true;
                for (int mask_iter : maskIndices) {
                    if (adjacencyMatrix[any_iter][mask_iter] == 0) {
                        conflict_node_exists = false;
                        break;
                    }
                }
                if (conflict_node_exists) {
                    return false;
                }
            }
        }
        return true;
    }

    public ArrayList<ArrayList<Integer>> getAllCliquesIndices() {
        calculateDistanceMatrix();
        calculateAdjacencyMatrix();
        ArrayList<ArrayList<Integer>> answer = new ArrayList<>();
        for (int bitMask = 1; bitMask < (1 << N); bitMask++) {
            ArrayList<Integer> maskIndices = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                int value = bitMask & (1 << i);
                if (value != 0) {
                    maskIndices.add(i);
                }
            }
            // maskIndices is sorted
            if (maskIndices.size() > 1 &&  checkMaskCorectness(maskIndices) && checkMaskCompleteness(maskIndices)) {
                answer.add(maskIndices);
            }
        }
        return answer;
    }

    static private int wordsDistance(String lhs, String rhs) {
        int ans = 0;
        int len = Math.min(lhs.length(), rhs.length());
        for (int i = 0; i < len; i++) {
            if (lhs.charAt(i) != rhs.charAt(i)) {
                ans++;
            }
        }
        return ans;
    }
}
