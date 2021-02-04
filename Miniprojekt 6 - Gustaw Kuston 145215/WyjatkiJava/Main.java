public class Main {
    public static void main(String[] args) throws AccountNotFoundException, AccountLoginFailedException,
            CustomerNotFoundException {
        Bank b1 = new Bank();
        Customer c1 = new Customer();
        Account a1 = new Account();
        try {
            a1 = b1.findByNumber(132);
        } catch(AccountNotFoundException e) {
            e.printStackTrace();
        }
        try {
            a1 = b1.findByNumber(132);
        } catch(AccountNotFoundException e) {
            e.fillInStackTrace();
            e.printStackTrace();
            // Slady sa inne, poniewaz fillInStackTrac nadpisalo poprzedni stos
        }
        try {
            a1.login("halo", 123);
        } catch(AccountLoginFailedException f) { }
        try {
            c1 = b1.findByName("Marek");
        } catch(CustomerNotFoundException g) { }
    }
}
