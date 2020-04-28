package io.github.lionell.lab4;

import java.util.function.Function;
import java.util.logging.Logger;

import io.github.lionell.lab4.logging.ThreadLogger;

public class Server1 {
  private static final int PORT = 12345;

  public static void main(String[] args) {
    Server server =
        new Server(
            PORT,
            new Function<String, Boolean>() {
              final Logger logger = ThreadLogger.of(Server.class);

              @Override
              public Boolean apply(String s) {
                int i = Integer.parseInt(s);
                try {
                  for (int j = 0; j < i; j++) {
                    Thread.sleep(1000);
                    logger.info((i - j) + " seconds left.");
                  }
                  return i % 2 == 0;
                } catch (InterruptedException ignored) {
                  return null;
                }
              }
            });
    server.run();
  }
}
