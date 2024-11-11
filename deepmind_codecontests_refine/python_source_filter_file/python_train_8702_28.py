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
x1,y1,x2,y2=map(int,input().split())
x,y=map(int,input().split())
if x1==x2 and y1==y2:
    print("YES")
else:
    if abs(x1-x2)%x==0 and abs(y1-y2)%y==0:
        if abs((abs(x1-x2)//x)-(abs(y1-y2)//x)) %2 == 0:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")

    
        
        
    
    