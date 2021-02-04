import java.util.ArrayList;

interface SearchCustomers {
    static Customer findByName (String name)
        throws CustomerNotFoundException {
            throw new CustomerNotFoundException("CustomerNotFoundException");
        }
}
interface SearchAccounts {
    static Account findByNumber(int number)
        throws AccountNotFoundException {
            throw new AccountNotFoundException("AccountNotFoundException - number");
        }
    static ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException {
            throw new AccountNotFoundException(cust);
        }
}


public class AccountLoginFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int password;
    private String login;
    private String name;
    private String adres;
    private long pesel;
    //pola odpowiadajace danym klienta oraz numerowi konta

    //przykladowe konstruktory
    AccountLoginFailedException() {
        password = 0;
        login = "login";
        name = "imie i nazwisko";
        adres = "adres zamieszkania";
        pesel = 11111111111L;
    }
    AccountLoginFailedException(String errorMsg, String s, int passwd) {
        // super(errorMsg);
        login = s;
        password = passwd;
        name = "imie i nazwisko";
        adres = "adres zamieszkania";
        pesel = 11111111111L;
        }
    AccountLoginFailedException(String l, int p, String n, String a, long pe) {
        login = l;
        password = p;
        name = n;
        adres = a;
        pesel = pe;
        }

    int getPassword() {
        return password;
    }
    String getLogin() {
        return login;
    }
    String getName() {
        return name;
    }
    String getAdres() {
        return adres;
    }
    long getPesel() {
        return pesel;
    }
}
