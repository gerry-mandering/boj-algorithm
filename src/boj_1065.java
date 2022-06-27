import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int count = 0;

		for (int i = 1; i <= n; i++)
		{
			if (is_arithmetic_progression(i))
				count++;
		}
		System.out.println(count);
	}

	public static int get_digit(int input) {
		int digit = 0;

		while (input > 0) {
			digit++;
			input /= 10;
		}
		return (digit);
	}

	public static boolean is_arithmetic_progression(int input) {
		int digit = get_digit(input);
		int	back_digit = 0, front_digit = 0, diff = 0;

		if (digit < 3)
			return (true);
		else {
			for (int i = 0; i < digit - 1; i++) {
				back_digit = input % 10;
				input /= 10;
				front_digit = input % 10;
				if (i == 0)
					diff = back_digit - front_digit;
				else
				{
					if (back_digit - front_digit != diff)
						return (false);
				}
			}
			return (true);
		}
	}
}
