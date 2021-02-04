// CO ZYSKUJEMY STOSUJAC INTERFEJSY

public class Customer {
    private String name;
    private String adres;
    private long pesel;
    public Customer() {
        name = "imie i nazwisko";
        adres = "adres zamieszkania";
        pesel = 11111111111L;
    }
    public Customer(String s) {
        name = s;
        adres = "adres zamieszkania";
        pesel = 11111111111L;
    }
    public String getName() {
        return name;
    }
    // @Override
    // @Override uzywa sie przy nadpisywaniu metody w subklasie
    public boolean equals(Customer c) {
        String tmp1 = name;
        String tmp2 = c.name;
        if (tmp1.equals(tmp2)) {
            return true;
        }
        return false;
    }
}
