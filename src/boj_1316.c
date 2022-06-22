#include <stdio.h>

int	is_group_word(char *input)
{
	int	alphabet[26] = {0};
	int	i = 0;

	while (input[i])
	{
		if (i == 0)
			alphabet[input[i] - 'a']++;
		else if (input[i] != input[i - 1])
			alphabet[input[i] - 'a']++;
		i++;
	}
	i = 0;
	while (i < 26)
	{
		if (alphabet[i] > 1)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int		repeat = 0;
	int		group_word_count = 0;
	char	word[100];

	scanf("%d", &repeat);
	for (int i=0; i<repeat; i++)
	{
		scanf("%s", word);
		if (is_group_word(word))
			group_word_count++;
	}
	printf("%d\n", group_word_count);
	return (0);
}
