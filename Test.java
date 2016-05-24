import java.util.*;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> mlc = new ArrayList<>();
        mlc.add(1);
        mlc.add(2);
        mlc.add(3);

        ListIterator<Integer> it1 = mlc.listIterator();
        ListIterator<Integer> it2 = mlc.listIterator();
        // it1.next();
        // it1.next();
        it1.remove();
        System.out.println(it2.next());
    }
}
