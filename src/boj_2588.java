import java.util.Scanner;

public class boj_2588 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        int i, j, k;

        a = sc.nextInt();
        b = sc.nextInt();

        i = b / 100;
        j = (b % 100) / 10;
        k = ((b % 100) % 10) / 1;

        System.out.println(a * k);
        System.out.println(a * j);
        System.out.println(a * i);
        System.out.println(a * b);
    }
}
