import java.nio.file.Files;
import java.nio.file.Paths;
import parcs.*;

public class Bluck {
    public static void main(String[] args) throws Exception {
        task curtask = new task();
        curtask.addJarFile("WordFinder.jar");
        String fileAsString = fromFile(curtask.findFile("input"));

        String firstHalf = fileAsString.substring(0, (fileAsString.length())/2);
        String secondHalf = fileAsString.substring((fileAsString.length())/2);

        AMInfo info1 = new AMInfo(curtask, null);
        point p1 = info1.createPoint();
        channel c1 = p1.createChannel();
        p1.execute("WordFinder");
        c1.write(firstHalf);

        AMInfo info2 = new AMInfo(curtask, null);
        point p2 = info2.createPoint();
        channel c2 = p2.createChannel();
        p2.execute("WordFinder");
        c2.write(secondHalf);

        System.out.println("Waiting for result...");
        long first = c1.readLong();
        long second = c2.readLong();
        long result = first + second;
        System.out.println("Result from first worker: "+first);
        System.out.println("Result from second worker: "+second);
        System.out.println("Result: " + result);
        curtask.end();
    }

    public static String fromFile(String filename) throws Exception {
        String out = Files.readString(Paths.get(filename));
        return out;
    }
}
