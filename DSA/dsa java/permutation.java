import java.util.ArrayList;

public class permutation {
    public static void main(String[] args) {
        // permutation("", "abc");
        ArrayList<String> ans = permut("", "abc");
        System.out.println(ans);
    }

    static void permutation(String p, String up) {
        if (up.isEmpty()) {
            System.out.println(p);
            return;
        }

        char ch = up.charAt(0);

        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);
            String s = p.substring(i, p.length());
            permutation(f + ch + s, up.substring(1));
        }
    }

    static ArrayList<String> permut(String p, String up) {
        if (up.isEmpty()) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        char ch = up.charAt(0);

        ArrayList<String> list = new ArrayList<>();

        for (int i = 0; i <= p.length(); i++) {
            String f = p.substring(0, i);
            String s = p.substring(i, p.length());
            list.addAll(permut(f + ch + s, up.substring(1)));
        }

        return list;

    }
}

// class Solution {
// public List<String> letterCombinations(String digits) {
// pad("", digits);
// }

// public ArrayList<String> pad(String p, String up) {

// if (up.isEmpty()) {
// ArrayList<String> list = new ArrayList<>();
// list.add(p);
// return list;
// }

// int digit = up.charAt(0) - '0';

// ArrayList<String> list = new ArrayList<>();
// int i = 0;
// if (i > 1 && i < 7) {

// for (i = (digit - 2) * 3; i < (digit - 1) * 3; i++) {
// char ch = (char) ('a' + 'i');
// list.addAll(pad(p + ch, up.substring(1)));

// }
// }

// else if (i == 7) {

// for (i = (digit - 2) * 3; i <= (digit - 1) * 3; i++) {
// char ch = (char) ('a' + 'i');
// list.addAll(pad(p + ch, up.substring(1)));

// }
// }

// else if (i == 8) {
// // for ( int i = (digit - 2) * 3 + 1 ; i < (digit) * 3 ; i++ )
// for (i = (digit * 2) + 3; i < (digit) * 3; i++) {

// char ch = (char) ('a' + 'i');
// list.addAll(pad(p + ch, up.substring(1)));
// }
// }

// else {

// for (i = digit * 2 + 4; i < (digit * 3) - 2; i++) {
// char ch = (char) ('a' + 'i');
// list.addAll(pad(p + ch, up.substring(1)));

// }
// }

// return list;
// }

// 7 - 15 - 18
// 8 - 19- 21
// 9 - 22 - 25
