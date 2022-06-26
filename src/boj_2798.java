import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		int number_of_cards = sc.nextInt();
		int	target_sum = sc. nextInt();

		int[] card_arr = new int[number_of_cards];
		for (int i = 0; i < number_of_cards; i++)
		{
			card_arr[i] = sc.nextInt();
		}

		System.out.println(find_nearest_sum(target_sum, card_arr, number_of_cards));
	}

	public static int find_nearest_sum(int target_sum, int[] card_arr, int number_of_cards)
	{
		int	sum = 0, nearest_sum = 0;

		for (int i = 0; i < number_of_cards; i++)
		{
			for (int j = i + 1; j < number_of_cards; j++)
			{
				for (int k = j + 1; k < number_of_cards; k++)
				{
					sum = card_arr[i] + card_arr[j] + card_arr[k];
					if (target_sum - sum >= 0 && target_sum - nearest_sum > target_sum - sum)
						nearest_sum = sum;
					if (nearest_sum == target_sum)
						return (nearest_sum);
					
				}
			}
		}
		return (nearest_sum);
	}
}
