int EBOB(int x, int y)
{
	return (y ? EBOB(y, x % y) : x);
}
