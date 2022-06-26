import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int repeat = sc.nextInt();
		int height, width, nth_customer;

		for (int i = 0; i < repeat; i++)
		{
			height = sc.nextInt();
			width = sc.nextInt();
			nth_customer = sc.nextInt();
			print_room_number(height, width, nth_customer);
		}
	}

	public static void print_room_number(int height, int width, int nth_customer)
	{
		if (nth_customer % height == 0)
		{
			System.out.print(height);
			if (nth_customer / height < 10)
			{
				System.out.print("0");
			}
			System.out.println(nth_customer / height);
		}
		else
		{
			System.out.print(nth_customer % height);
			if (nth_customer / height + 1 < 10)
			{
				System.out.print("0");
			}
			System.out.println(nth_customer / height + 1);
		}
	}
}
