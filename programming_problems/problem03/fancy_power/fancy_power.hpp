#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancy_power(int n, int m)
{
	//base case: 
	if(n==0){
		return 1; //antyhing to the zero power is equal to 1
	}

	//function calls upon itself 
	//tests if n is even: 
	if(n%2==0){
		m = m*m; //m = m^2 now 
		n = n/2; //n is now n/2
		return fancy_power(m, n); //return m^n
	}
	//if n is odd: 
	else{ 
		m = m*m*m; //m is now m(m^2)
		n = (n-1)/2; //n is now (n-1)/2
		return fancy_power(m, n); //return m^n 
	}
	//gets us closer to the solution 

	//return 0;
}

#endif
