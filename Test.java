import java.util.*;

public class Test {
    public static void main(String[] args) {
        ArrayList<Integer> mlc = new ArrayList<>();
        mlc.add(1);
        mlc.add(2);
        mlc.add(3);

        ListIterator<Integer> it = mlc.listIterator();
        it.next();
        it.next();
        it.remove();
        // System.out.println(it.previous());
        System.out.println(it.next());
    }
}
