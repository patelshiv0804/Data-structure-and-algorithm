import java.util.ArrayList;

public class subset {
    public static void main(String[] args) {
        // subseq("", "abc");
        // System.out.println(subseqret("", "abc"));
        // subseqascii("", "abc");
        System.out.println(subseqascii1("", "abc"));
    }

    static void subseq(String p, String up) {

        if (up.isEmpty()) {
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        subseq(p + ch, up.substring(1));
        subseq(p, up.substring(1));
    }

    // if you have to store the answer into arraylist then...
    static ArrayList<String> subseqret(String p, String up) {

        if (up.isEmpty()) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        char ch = up.charAt(0);

        ArrayList<String> left = subseqret(p + ch, up.substring(1));
        ArrayList<String> right = subseqret(p, up.substring(1));

        left.addAll(right);
        return left;

    }

    // if you have to print the ascii value with character

    static void subseqascii(String p, String up) {

        if (up.isEmpty()) {
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        subseqascii(p + ch, up.substring(1));
        subseqascii(p + (ch + 0), up.substring(1));
        subseqascii(p, up.substring(1));
    }

    // In array list
    static ArrayList<String> subseqascii1(String p, String up) {

        if (up.isEmpty()) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        char ch = up.charAt(0);

        ArrayList<String> left = subseqascii1(p + ch, up.substring(1));
        ArrayList<String> middle = subseqascii1(p + (ch + 0), up.substring(1));
        ArrayList<String> right = subseqascii1(p, up.substring(1));

        left.addAll(right);
        left.addAll(middle);

        return left;
    }

}
