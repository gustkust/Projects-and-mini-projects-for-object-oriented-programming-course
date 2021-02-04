

public class AccountNotFoundException extends Exception {
    private static final long serialVersionUID = 1L;

    public AccountNotFoundException(String t) {
        System.out.println(t);
    }
    public AccountNotFoundException(Customer t) {
        System.out.println(t.getName());
    }
    public AccountNotFoundException(int t) {
        System.out.println(t);
    }
}
