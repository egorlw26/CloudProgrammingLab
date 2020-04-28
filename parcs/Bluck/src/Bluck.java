import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.File;
import parcs.*;

public class Bluck {
    public static void main(String[] args) throws Exception {
        task curtask = new task();
        curtask.addJarFile("WordFinder.jar");
        String n = fromFile(curtask.findFile("input"));

        AMInfo info = new AMInfo(curtask, null);
        point p = info.createPoint();
        channel c = p.createChannel();
        p.execute("WordFinder");
        c.write(n);

        System.out.println("Waiting for result...");
        System.out.println("Result: " + c.readLong());
        curtask.end();
    }

    public static String fromFile(String filename) throws Exception {
        String out = Files.readString(Paths.get(filename));
        return out;
    }
}
