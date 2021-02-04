

public class CustomerNotFoundException extends Exception {
    private static final long serialVersionUID = 1L;

    public CustomerNotFoundException(String t) {
        System.out.println(t);
    }
}
