import parcs.*;

public class WordFinder implements AM {
    public void run(AMInfo info) {
        String fileAsString = (String)info.parent.readObject();
        System.out.println("Build started.");

        String[] words = fileAsString.split(" ");
        long sum = 0;

        for (String word : words)
            if (word.equals("Drizzt")) {
                sum++;
            }

        System.out.println("Build finished.");
        info.parent.write(sum);
    }
}
