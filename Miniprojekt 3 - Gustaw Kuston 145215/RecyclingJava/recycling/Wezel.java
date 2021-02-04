package recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.Comparator;


// comparator dla treemap
class WezelComp implements Comparator<Wezel> {
    public int compare(Wezel w1, Wezel w2) {
        return w1.dajKlucz() - w2.dajKlucz();
    }
}

public class Wezel {
    // W tym przypadku arraylist jest lepszy od zwyklej listy,
    // poniewaz przy inicjacji nie trzeba podawac rozmiaru,
    // a dodawanie elementow nie wymaga specyfikacji
    // pozycji, na ktora dodajemy.
    public ArrayList<Wezel> polaczenia = new ArrayList<Wezel>();
    // Hashmap
    public HashMap<Wezel,Boolean> polaczeniahash = new HashMap<Wezel,Boolean>();
    // Treemap
    public TreeMap<Wezel,Integer> polaczeniatree = new TreeMap<Wezel,Integer>(new WezelComp());

    // zmienna sluzaca jako klucz w treemap
    public int klucz;
    public int dajKlucz() {
        return this.klucz;
    }

    @Deprecated
    @Override
    protected void finalize() throws Throwable {
        // Przy 10 000 nic sie nie drukuje, a przy 1 000 000 tak,
        // poniewaz nastąpiło przepełnienie pamięci i musiała zostać zwolniona.
        System.out.println( "Finalizowanie obiektu" ) ;
        super.finalize() ;
    }
    public static void main (String [] args) {
        Scanner s = new Scanner (System.in) ;

        // Wersja z arraylist:
        for (int i = 0; i <= 1000000; i++) {
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            // Program nadal drukuje, poniewaz mimo, ze odwolania sa w listach,
            // to i tak nastapilo przepelnienie pamieci i musiala zostac zwolniona.
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }

        // // Wersja z hashmap:
        // for (int i = 0; i <= 1000000; i++) {
        //     Wezel w1 = new Wezel();
        //     Wezel w2 = new Wezel();
        //     w1.dodajPolaczenieHash(w2);
        //     w2.dodajPolaczenieHash(w1);
        // }

        // // Wersja z treemap:
        // for (int i = 0; i <= 1000000; i++) {
        //     Wezel w1 = new Wezel();
        //     w1.klucz = i * 2;
        //     Wezel w2 = new Wezel();
        //     w2.klucz = i * 2 + 1;
        //     w1.dodajPolaczenieTree(w2);
        //     w2.dodajPolaczenieTree(w1);
        // }

        s.nextLine();
        s.close();
    }
    // DodajPolaczenie dla arraylist:
    public void dodajPolaczenie(Wezel polaczenie) {
        polaczenia.add(polaczenie);
    }
    // DodajPolaczenie dla hashlist:
    public void dodajPolaczenieHash(Wezel polaczenie) {
        polaczeniahash.put(polaczenie, true);
    }
    // DodajPolaczenie dla treelist:
    public void dodajPolaczenieTree(Wezel polaczenie) {
        polaczeniatree.put(polaczenie, polaczenie.dajKlucz());
    }
    }