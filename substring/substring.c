#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"

/**
 *check_word_match - checks if a substring matches word
 *@substring: substring
 *@words: array of words to match
 *@nb_words: number of elements
 *@len: length of each word
 *@visited: array of words
 *
 *Return: 1 match 0 otherwise
 */
static int check_word_match(const char *substring, const char **
		words, int nb_words, int len, int *visited)
{
	int k;

	for (k = 0; k < nb_words; k++)
	{
		if (!visited[k] && strncmp(substring, words[k], len) == 0)
		{
			visited[k] = 1;
			return (1);
		}
	}

	return (0);
}

/**
 *process_substring - procces a substring
 *@s: string
 *@words: array of words
 *@nb_words: number of elements
 *@len: length of each word
 *@indices: array of res
 *@n: current count of indices
 *@i: current index being processed
 *
 *Return: count of valid indices
 */
static int process_substring(const char *s, const char **
		words, int nb_words, int len, int *indices, int n, int i)
{
	int j;
	int *visited = calloc(nb_words, sizeof(int));
	int found = 1;

	if (visited == NULL)
	{
		free(indices);
		return (-1);
	}

	for (j = 0; j < nb_words; j++)
	{
		found = check_word_match(s + i + j * len, words, nb_words, len, visited);
		if (!found)
			break;
	}

	free(visited);

	if (found)
	{
		indices[n] = i;
		n++;
	}

	return (n);
}

/**
 *find_substring - scan for possible substrings
 *@s: string
 *@words: arary of substrings
 *@nb_words: number of elements
 *@n: address
 *
 *Return: allocated array
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int leng = strlen(words[0]);
	int word_length = leng * nb_words;
	int str_len = strlen(s);
	int *indices = NULL;
	int i;

	*n = 0;

	if (str_len == 0 || word_length > str_len)
		return (NULL);

	indices = malloc(str_len * sizeof(int));
	if (indices == NULL)
		return (NULL);

	for (i = 0; i <= str_len - word_length; i++)
	{
		*n = process_substring(s, words, nb_words, leng, indices, *n, i);
		if (*n == -1)
			return (NULL);
	}

	if (*n == 0)
	{
		free(indices);
		indices = NULL;
	}

	return (indices);
}
