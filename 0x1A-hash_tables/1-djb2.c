/**
 * hash_djb2 - The function(method) that implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int n;

	hash = 5381;
	while ((n = *str++))
	{
		hash = ((hash << 5) + hash) + n; /* hash * 33 + n */
	}
	return (hash);
}
