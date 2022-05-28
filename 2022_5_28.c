int gcd(int a, int b) {

	// write code here
	int n = a % b;
	while (n)
	{
		a = b;
		b = n;
		n = a % b;
	}

	//     if(b==0)
	//         return a;
	//     else
	//         return gcd(b,a%b);

	//     while(a!=b)
	//     {
	//         if(a>b)
	//             a-=b;
	//         else
	//             b-=a;
	//     }
	//     return a;
}