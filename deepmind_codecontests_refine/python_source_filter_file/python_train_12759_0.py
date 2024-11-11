#Winners never quit, quiters never win............................................................................
from collections import deque as de
import math
from collections import Counter as cnt
from functools import reduce
from typing import MutableMapping
from itertools import groupby as gb

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
class My_stack():
    def __init__(self):
        self.data = []
    def my_push(self, x):
        return (self.data.append(x))
    def my_pop(self):
        return (self.data.pop())
    def my_peak(self):
        return (self.data[-1])
    def my_contains(self, x):
        return (self.data.count(x))
    def my_show_all(self):
        return (self.data)
    def isEmpty(self):
      return len(self.data)==0

arrStack = My_stack()    
def decimalToBinary(n): 
    return bin(n).replace("0b", "")

def isPrime(n) : 
	if (n <= 1) : 
		return False
	if (n <= 3) : 
		return True

	
	if (n % 2 == 0 or n % 3 == 0) : 
		return False

	i = 5
	while(i * i <= n) : 
		if (n % i == 0 or n % (i + 2) == 0) : 
			return False
		i = i + 6

	return True

def get_prime_factors(number):
    prime_factors = []
    while number % 2 == 0:
        prime_factors.append(2)
        number = number / 2
    for i in range(3, int(math.sqrt(number)) + 1, 2):
        while number % i == 0:
            prime_factors.append(int(i))
            number = number / i

    if number > 2:
        prime_factors.append(int(number))

    return prime_factors
def get_frequency(list):
    dic={}
    for ele in list:
        if ele in dic:
            dic[ele] += 1
        else:
            dic[ele] = 1
    return dic
def Log2(x): 
    return (math.log10(x) / 
            math.log10(2)); 

def isPowerOfTwo(n): 
    return (math.ceil(Log2(n)) == math.floor(Log2(n))); 

   
#here we go......................
#Winners never quit, Quitters never win
s=input()
if len(set(s))==1 and s[0]=="a":
    print("z"*len(s))
else:
    
    aa=0
    st=0
    fn=0
    cntt=0
    for i in range(len(s)):
        if cntt==0:
            if aa==0 and s[i]!="a":
                aa=1
                st=i
            if aa==1 and s[i]=="a":
                aa=0
                fn=i-1
                cntt=1
    if aa==1:
        fn=len(s)-1    
    ans=""
    for i in range(len(s)):
        if st <=i <=fn:
            #print(s[i])
            kk=ord(s[i])
            ans+=chr(kk-1)
        else:
            ans+=s[i]
    print(ans)
            


    
            
        
        