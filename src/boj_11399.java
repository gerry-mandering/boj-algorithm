import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner	sc = new Scanner(System.in);
		int		total_time;
		int		people_total = sc.nextInt();
		int[]	each_time_arr = new int[people_total];

		for (int i = 0; i < people_total; i++)
		{
			each_time_arr[i] = sc.nextInt();
		}
		
		bubble_sort(each_time_arr, people_total);

		total_time = get_total_time(each_time_arr, people_total);
		
		System.out.println(total_time);
	}

	public static void bubble_sort(int[] arr, int size)
	{
		int temp;

		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	public static int get_total_time(int[] each_time_arr, int size)
	{
		int	sum = 0;

		if (size == 0)
			return (0);
		else
		{
			for (int i = 0; i < size; i++)
			{
				sum += each_time_arr[i];
			}

			return (sum + (get_total_time(each_time_arr, size - 1)));
		}
	}
}
