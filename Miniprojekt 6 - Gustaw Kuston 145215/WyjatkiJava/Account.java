public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;
    public Account() {
        accountNumber = 0;
        password = 0;
        login = "login";
        balance = 0;
    }
    public Account(int n, Customer c, int p, String l) {
        accountNumber = n;
        owner = c;
        password = p;
        login = l;
        balance = 0;
    }
    public Account(String error_msg) {
        System.out.println(error_msg);
    }
    public void login(String l, int passwd) 
        throws AccountLoginFailedException {
            throw new AccountLoginFailedException();
        }
    public Customer getCustomer() {
        return owner;
    }
    public int getNumber() {
        return accountNumber;
    }
    public double getBalance() {
        return balance;
    }
    public double withdraw(double amount) {
        balance = balance - amount;
        return balance;
    }

}
