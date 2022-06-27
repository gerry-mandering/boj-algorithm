import java.util.Scanner;

public class Main {

	static int MAX_SIZE = 1000;
	static int[] arr = new int[MAX_SIZE];
	static int	size, start, rear;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int	total_people = sc.nextInt();
		int	nth_person = sc.nextInt();
		int index = 0, i = 0;

		for (int j = 0; j < total_people; j++)
		{
			enqueue(j + 1);
		}
		System.out.printf("<");
		while (i < total_people)
		{
			index = (index + nth_person - 1) % size;
			System.out.printf("%d", dequeue(index));
			if (size != 0)
				System.out.printf(", ");
			i++;
		}
		System.out.printf(">");
	}

	public static void enqueue(int input)
	{
		if (size == MAX_SIZE)
			System.out.printf("Full\n");
		else
		{
			arr[rear % 1000] = input;
			size++;
			rear++;
		}
	}

	public static int dequeue(int index)
	{
		if (size == 0)
		{
			System.out.printf("Empty\n");
			return (0);
		}
		else
		{
			int	return_val = arr[index];
			push_one_front(index);
			size--;
			return (return_val);
		}
	}

	public static void push_one_front(int index)
	{
		for (int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}
