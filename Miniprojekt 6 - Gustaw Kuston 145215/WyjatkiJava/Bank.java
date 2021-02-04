import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();
    // @Override
    public Customer findByName (String name)
        throws CustomerNotFoundException {
            throw new CustomerNotFoundException(name);
        }
    // @Override
    public Account findByNumber(int num)
        throws AccountNotFoundException {
            throw new AccountNotFoundException(num);
        }
    // @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException {
            throw new AccountNotFoundException(cust);
        }
    public void addCustomer(Customer t) {
        customers.add(t);
    }
    public void addAccount(Account t) {
        accounts.add(t);
    }
}