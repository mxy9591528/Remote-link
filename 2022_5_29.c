bool square(int c) {
	// write code here
	for (int i = 1; i < sqrt(c); i++)
	{
		if (sqrt(c - i * i) == (int)sqrt(c - i * i))//����˼ά
			return true;
	}
	return false;
}