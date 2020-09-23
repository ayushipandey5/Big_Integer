#include<bits/stdc++.h> 
using namespace std; 

//MULTIPLY

string multiply(string num1, string num2) 
{ 
    int flag = 0;

	if((num1.at(0) == '-' || num2.at(0) == '-') && (num1.at(0) != '-' || num2.at(0) != '-' )) 
	    flag=1;

	if(num1.at(0) == '-' && num2.at(0)!='-') 
	{ 
		num1 = num1.substr(1); 
	} 
	else if(num1.at(0) != '-' && num2.at(0) == '-') 
	{ 
		num2 = num2.substr(1); 
	} 
	else if(num1.at(0) == '-' && num2.at(0) == '-') 
	{ 
		num1 = num1.substr(1); 
		num2 = num2.substr(1); 
	} 


	int len1 = num1.size(); 
	int len2 = num2.size(); 
	if (len1 == 0 || len2 == 0) 
	return "0"; 
	
	int size = len1+len2;
	
	int result[size]; 
	for(int i=0;i<size;i++)
		result[i] = 0;

	int i_n1 = 0; 
	int i_n2 = 0; 
	
	for (int i=len1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		i_n2 = 0; 
		

		for (int j=len2-1; j>=0; j--) 
		{ 

			int n2 = num2[j] - '0'; 
			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
			carry = sum/10; 

			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 
		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 
		i_n1++; 
	} 

	int i = size - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 

	if (i == -1) 
	return "0"; 

	string s = ""; 

	if(flag==1){
		s += "-";
	}
	
	while (i >= 0) 
		s += std::to_string(result[i--]); 

	return s; 
} 

// Comparing two nums

int comp(string a, string b){
    long long len1 = a.size();
    long long len2 = b.size();
    if(len1>len2)
        return 1;
    else if(len2>len1)
        return -1;
    else{
        for(long long i=0;i<len1;i++){
            int ai = a[i] -'0';
            int bi = b[i] - '0';
            if(ai>bi)
                return 1;
            else if(ai<bi)
                return -1;
        }
        return 0;
    }
}




//ADDITION

string add(string n1,string n2){
    
    string s = ""; 
    
    string num1 = n1;
    string num2 = n2;
    
    if((n1.compare(n2))<0){
        num1 = n2;
        num2 = n1;
    }

	int len1 = num1.size(); 
	int len2 = num2.size(); 
	    
	if (len1 == 0 && len2 == 0) 
	   return "0"; 
	
	int size = max(len1,len2) + 1;
	    
	
	int result[size]; 
	for(int i=0;i<size;i++)
	    result[i] = 0;
		
	if(len1>len2){
	    int carry = 0;
	    for(int i=1;i<=len2;i++){
	       int sum = num2[len2-i] - '0' + num1[len1-i] - '0' + carry;
	       carry = sum/10;
	       result[size-i]=sum%10;
	    }
	    for(int i=len2+1;i<=len1;i++){
    	   int sum = num1[len1-i] - '0' + carry;
	       carry = sum/10;
    	   result[size-i]=sum%10;
	    }
	    if(carry>0)
    	  result[0]=carry;
	 }
	 else{
	    int carry = 0;
	    for(int i=1;i<=len1;i++){
            int sum = num2[len2-i] - '0' + num1[len1-i] -'0' + carry;
	        carry = sum/10;
	        result[size-i]=sum%10;
	    }
	    if(carry>0)
    	   result[0]=carry;
	}
	    
	int i = 0; 
	while (i<size && result[i] == 0) 
	      i++; 
	
	while (i<size) 
	s += std::to_string(result[i++]);
	return s; 
}

//SUBRACTION
	
string subtract(string num1,string num2){
	
	    string s;
	    
	    int len1 = num1.size();
	    int len2 = num2.size();
	    
	    
	    if (len1 == 0 && len2 == 0) 
	        return "0"; 
	    
	    else if(num1.compare(num2) == 0) 
	        return "0";
	    
	    int size = max(len1,len2);
	
	    int result[size]; 
	    for(int i=0;i<size;i++)
		    result[i] = 0;
		    
		if(len1>len2){
	        int borrow = 0;
	        for(int i=1;i<=len2;i++){
	           if(num1[len1-i]>num2[len2-i]){
	               int diff = num1[len1-i] - num2[len2-i] - borrow;
	               result[size-i]= diff % 10;
	               borrow = 0;
	           }
	           else if(num1[len1-i]<num2[len2-i]){
	               int diff = num1[len1-i] + 10 - num2[len2-i] - borrow;
	               borrow = 1;
	               result[size-i] = diff%10;
	           }
	           else if(num1[len1-i]==num2[len2-i]){
	               if(borrow == 1){
	                   result[size-i] = 9;
	                   borrow = 1;
	               }
	               else{
	                   result[size-i] = 0;
	                   borrow = 0;
	               }
	           }
	        }
	        for(int i=len2+1;i<=len1;i++){
	            if(num1[len1-i] == '0'){
	                int diff = num1[len1-i] + 10 - '0' - borrow;
	                result[size-i] = diff%10;
	                borrow = 1;
	            }
	            else{
	                result[size-i] = num1[len1-i] - '0' - borrow;
	                borrow = 0;
	            }
	        }
		}
		
		
        else if(len1<len2){
	        int borrow = 0;
	        for(int i=1;i<=len1;i++){
	           if(num2[len2-i]>num1[len1-i]){
	               int diff = num2[len2-i] - num1[len1-i] - borrow;
	               result[size-i]= diff % 10;
	               borrow = 0;
	           }
	           else if(num2[len2-i]<num1[len1-i]){
	               int diff = num2[len2-i] + 10 - num1[len1-i] - borrow;
	               borrow = 1;
	               result[size-i] = diff%10;
	           }
	           else if(num1[len1-i]==num2[len2-i]){
	               if(borrow == 1){
	                   result[size-i] = 9;
	                   borrow = 1;
	               }
	               else{
	                   result[size-i] = 0;
	                   borrow = 0;
	               }
	           }
	        }
	        for(int i=len1+1;i<=len2;i++){
	            if(num2[len2-i] == '0'){
	                int diff = num2[len2-i] + 10 - '0' - borrow;
	                result[size-i] = diff%10;
	                borrow = 1;
	            }
	            else{
	                result[size-i] = num2[len2-i] - '0' - borrow;
	                borrow = 0;
	            }
	        }
		}
		
		
		
	    else if(len1 == len2){
	        if((num1.compare(num2))<0){
	            int borrow = 0;
	            for(int i=1;i<=len1;i++){
	                if(num2[len2-i]>num1[len1-i]){
	                    int diff = num2[len2-i] - num1[len1-i] - borrow;
	                    result[size-i]= diff % 10;
	                    borrow=0;
	                }
	                else if(num2[len2-i]<num1[len1-i]){
	                        int diff = num2[len2-i] + 10 - num1[len1-i] - borrow;
        	                borrow = 1;
	                        result[size-i] = diff%10;
	                }
	                else if(num1[len1-i]==num2[len2-i]){
	                    if(borrow == 1){
	                        result[size-i] = 9;
	                        borrow = 1;
	                    }
	                    else{
	                        result[size-i] = 0;
	                        borrow = 0;
    	               }
	               }
	            }   
	        }
	        else if((num1.compare(num2))>0){
	            int borrow = 0;
	            for(int i=1;i<=len2;i++){
	                if(num1[len1-i]>num2[len2-i]){
	                    int diff = num1[len1-i] - num2[len2-i] - borrow;
	                    result[size-i]= diff % 10;
	                    borrow = 0;
	                }
	                else if(num1[len1-i]<num2[len2-i]){
	                    int diff = num1[len1-i] + 10 - num2[len2-i] - borrow;
	                    borrow = 1;
	                    result[size-i] = diff%10;
	                }
	                else if(num1[len1-i]==num2[len2-i]){
	                    if(borrow == 1){
	                        result[size-i] = 9;
	                        borrow = 1;
	                    }
	                    else{
	                        result[size-i] = 0;
	                        borrow = 0;
	                    }
	                }
	            }
	        }
	    }
	    
	    int i = 0; 
	    while (i<size && result[i] == 0) 
	        i++; 

	
	    while (i<size) 
		    s += std::to_string(result[i++]);
		    
	return s;  
}


// FACTORIAL

string factorial(int n){
    
    string s = std::to_string(n);
    int r = n-1;
    
    while(r != 1){
        string p= std::to_string(r);
        s = multiply(s,p);
        r = r-1;
    }
    
    return s;
}

//FAST EXPONENTIATION

string fast_expo(string a,long long b){
    string result="1";
    
    while(b>0){
        if(b&1)
            result = multiply(result,a);
        a = multiply(a,a);
        b>>=1;
    }
    
    return result;
}


//DIVISION

string divideByTwo(string number) 
{ 
    
    string ans=""; 
  
    
    int index = 0; 
    int temp = number[index] - '0'; 
    if(temp < 2) {
        temp = temp * 10 + (number[++index] - '0'); 
    }

    while (number.size() > index) { 
        ans += (temp>>1) + '0'; 
        temp = (temp % 2) * 10 + number[++index] - '0'; 
    } 
  
    if (ans.length() == 0) 
        return "0"; 
  
    return ans; 
} 



bool isEven(string a){
    int len = a.size();
    int last;
    if(len)
        last = a[len-1] - '0';
    if(last%2 == 0)
        return 1;
    else
        return 0;
}  

//GCD

string gcd(string num1, string num2){
    
    string a=num1;
    string b=num2;
    
    if(comp(a,b)==-1){
        a = num2;
        b = num1;
    }
    
    if(a=="0" && b=="0")
        return 0;
    else if(a=="0")
        return b;
    else if(b=="0")
        return a;
        
    long long k=0;
    string result;
    
    while(comp(a,"0")==1){
        while((isEven(a)==1) && (isEven(b)==1)){
            k += 1;
            a = divideByTwo(a);
            b = divideByTwo(b);
        }
        if(isEven(a)==1)
            a = divideByTwo(a);
        if(isEven(b)==1)
            b = divideByTwo(b);
            
        else if((isEven(a)==0) && (isEven(b)==0)){
            string temp = subtract(a,b);
            if(comp(b,a)==1)
                b=a;
            a = divideByTwo(temp);
            
        }
    }
    
    string inter = fast_expo("2",k);
    result = multiply(inter,b);
    return result;
}   
 

//Driver Code
int main() 
{ 
	int Q;
	cin>>Q;
	while(Q--){
		int q_no;
		cin>> q_no;
		if(q_no == 1){
			string A;
			long long B;
			cin>>A;
			cin>>B;
			cout<<fast_expo(A,B)<<endl;
		}
		else if(q_no == 2){
			string A;
			string B;
			cin>>A;
			cin>>B;
			cout<<gcd(A,B)<<endl;
		}
		else if(q_no == 3){
			int A;
			cin>>A;
			cout<<factorial(A)<<endl;
		}
	}
	
	return 0; 
} 

