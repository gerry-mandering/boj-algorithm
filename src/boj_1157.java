import java.util.Arrays;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

public class boj_1157 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        Integer[] count = new Integer[26];

        for (int i = 0; i < count.length; i++) {
            count[i] = 0;
        }

        str = sc.nextLine();

        str = str.toUpperCase(Locale.ROOT);

        for (int i=0; i<str.length(); i++) {
            for (char j = 'A'; j <= 'Z'; j++) {
                if (str.charAt(i) == j) {
                    count[((int)j)-65]++;
                }
            }
        }
        Integer[] count2 = new Integer[26];
        count2 = count.clone();
        Arrays.sort(count2, Collections.reverseOrder());

        if (count2[0].equals(count2[1])) {
            System.out.println("?");
        } else {
            char j = 'A';
            for (int i=0; i<count.length; i++) {
                j = (char)++j;
                if (count[i].equals(count2[0])) {
                    break;
                }
            }
            j = (char)(j-1);
            System.out.println(j);
        }

    }
}
