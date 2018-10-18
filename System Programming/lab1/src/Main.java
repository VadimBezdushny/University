import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedHashSet;

public class Main {

    private static ArrayList<String> readWordsFromFile(String file_path) {
        String text = "";
        try {
            text = new String(Files.readAllBytes(Paths.get(file_path)));
        } catch (IOException e) {
            e.printStackTrace();
        }
        return new ArrayList<>(new LinkedHashSet<>(Arrays.asList(text.split("\\W+"))));
    }

    public static void main(String[] args) {
        String file_name = "words3.txt";
        if(args.length > 1){
            file_name = args[0];
        }
        ArrayList<String> words = readWordsFromFile(file_name);
        System.out.println("Input words:" + words);

        Graph graph = new Graph(words);
        ArrayList<ArrayList<Integer>> cliques = graph.getAllCliquesIndices();

        System.out.printf("Generated %d cliques:\n", cliques.size());
        for (ArrayList<Integer> clique_entry : cliques) {
            String previousSeparator = "";
            System.out.print("[");
            for (Integer node_index : clique_entry) {
                System.out.print(previousSeparator + words.get(node_index));
                previousSeparator = ",";
            }
            System.out.print("]\n");
        }
    }
}
