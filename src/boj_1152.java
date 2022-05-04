import java.util.Scanner;

public class boj_1152 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text;
        int index = 1;
        text = sc.nextLine();
        
        for (int i=0; i<text.length(); i++) {
            if (text.charAt(i) == ' ') {
                index++;
            }
        }

        if (text.charAt(0) == ' ') {
            index--;
        }
        if (text.charAt(text.length() - 1) == ' ') {
            index--;
        }

        System.out.println(index);
    }
}
