package processor.exceptions;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class CoreException extends RuntimeException {
    public CoreException(String message) {
        super(message);
    }

    @Override
    public String getMessage() {
        return "Core Error: " + super.getMessage();
    }
}
