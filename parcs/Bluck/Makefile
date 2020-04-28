all: run

clean:
	rm -f out/Bluck.jar out/WordFinder.jar

out/Bluck.jar: out/parcs.jar src/Bluck.java
	@javac -cp out/parcs.jar src/Bluck.java
	@jar cf out/Bluck.jar -C src Bluck.class
	@rm -f src/Bluck.class

out/WordFinder.jar: out/parcs.jar src/WordFinder.java
	@javac -cp out/parcs.jar src/WordFinder.java
	@jar cf out/WordFinder.jar -C src WordFinder.class
	@rm -f src/WordFinder.class

build: out/Bluck.jar out/WordFinder.jar

run: out/Bluck.jar out/WordFinder.jar
	@cd out && java -cp 'parcs.jar:Bluck.jar' Bluck
