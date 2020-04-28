package io.github.lionell.lab1;

import com.google.common.base.Joiner;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import io.github.lionell.lab1.io.WordReader;

/**
 * Usage example: $ bazel run //java/io/github/lionell/lab1 --
 * /home/lionell/dev/labs/volohov/res/in.txt
 * /home/lionell/dev/labs/volohov/res/out.txt
 *
 * @author lionell
 */
public class Runner {
  public static void main(String[] args) throws IOException {
    WordReader reader = new WordReader(args[0]);
    System.out.println(args[0]);

    List<String> words = new ArrayList<>();
    while (reader.hasNext()) {
      words.add(reader.next());
    }

    reader.close();

    // FrequencySorter.sort(words);
    // System.out.println(Joiner.on(", ").join(words));

    Set<Set<String>> sets = new CliquesFinder(words).findCliques();

    PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(args[1])));

    for (Set<String> set : sets) {
      writer.println("{" + Joiner.on(", ").join(set) + "}");
    }

    writer.close();
  }
}
