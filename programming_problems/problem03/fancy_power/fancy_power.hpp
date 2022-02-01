#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

int fancy_power(int n, int m)
{	
	//define variable to return:
	//int fancypower; 

	//add a stop case: 
	// if(n==1){ 
	// 	fancypower =  m;
	// }

	//base case: 
	if(n==0){
		return 1; //antyhing to the zero power is equal to 1
	}
	//function calls upon itself 
	//tests if n is even: 
	if(n%2==0){
		//m = m*m; //m = m^2 now 
		//n  = n/2; //n is now n/2
		return fancy_power((n/2), (m*m)); //return m^n
	}
	//if n is odd: 
	else{ 
		//m = m*m; //m is now m(m^2)
		//n = (n-1)/2; //n is now (n-1)/2
		return m*fancy_power(((n-1)/2), (m*m)); //return m^n 
	}
	//gets us closer to the solution 	
	//return 0; Does not work as a stop case
	//return fancypower; //return whatever result you get for the fancypower  
}

#endif
