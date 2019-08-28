/**
 * string_to_int - converts string to integers
 * @s: string passed to us
 *
 * Return: @result the new number
 */
int string_to_int(char *s)
{
	int result = 0;
	int i = 0;

	/* loop through string and update result by */
	/* multiplying by 10 first and then adding the digit */
	for (i = 0; s[i] != '\0'; i++)
	{
		result = result * 10 + s[i] - '0';
	}
	/* returns the result */
	return (result);
}
