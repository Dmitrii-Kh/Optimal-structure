import java.util.*;
import static java.lang.Character.isLetter;

class Node {
    int data;
    char c;
    Node left;
    Node right;
}

class MyComparator implements Comparator<Node> {
    public int compare(Node x, Node y) {
        return x.data - y.data;
    }
}

    public class Huff {
    public static void printCode(Node root, String s) {
        if (root.left == null
                && root.right == null
                && isLetter(root.c)) {
            System.out.println("'" + root.c + "'" + ":" + s);
            return;
        }
        printCode(root.left, s + "0");
        printCode(root.right, s + "1");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string : ");
        String givenText = sc.nextLine();
        char []charArray0 = givenText.toCharArray();
        int n = charArray0.length;

        TreeMap<java.lang.Character, Integer> userList = new TreeMap<>();
        int tempCount = 0;
        for (int i = 0; i < n; i++) {
            if (userList.containsKey(givenText.charAt(i))) {
                tempCount = userList.get(givenText.charAt(i)) + 1;
                userList.put(givenText.charAt(i), tempCount);
            } else {
                userList.put(givenText.charAt(i), 1);
            }
        }
        int listSize = userList.size();
        System.out.println(userList.entrySet());

        int[] charfreq = new int[listSize] ;
        char[] charArray = new char[listSize];
        int j = 0;
        for (Map.Entry e : userList.entrySet()) {
            charArray[j] = (char)e.getKey();
            charfreq[j] = (int)e.getValue();
            j++;
        }

        PriorityQueue<Node> q
                = new PriorityQueue<Node>(listSize, new MyComparator());

        for (int i = 0; i < listSize; i++) {
            Node hn = new Node();

            hn.c = charArray[i];
            hn.data = charfreq[i];
            hn.left = null;
            hn.right = null;

            q.add(hn);
        }
        Node root = null;

        while (q.size() > 1) {
            Node x = q.peek();
            q.poll();

            Node y = q.peek();
            q.poll();

            Node f = new Node();
            f.data = x.data + y.data;
            f.c = '-';
            f.left = x;
            f.right = y;

            root = f;
            q.add(f);
        }
        printCode(root, "");
    }
}

