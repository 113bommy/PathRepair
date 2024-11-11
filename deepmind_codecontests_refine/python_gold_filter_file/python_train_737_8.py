#Mamma don't raises quitter.................................................
from collections import deque as de
import math
from sys import stdin, stdout
import re
from collections import Counter as cnt
from functools import  reduce

from itertools import groupby as gb
#from fractions import Fraction as fr
from bisect import bisect_left as bl, bisect_right as br

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

#decimal to binary   
def decimalToBinary(n): 
    return bin(n).replace("0b", "")
#binary to decimal
def binarytodecimal(n):
    return int(n,2)

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

 
# Function to get product of digits
def getProduct(n):
 
    product = 1
 
    while (n != 0):
        product = product * (n % 10)
        n = n // 10
 
    return product


#function to find LCM of two numbers
def lcm(x,y):
   lcm = (x*y)//math.gcd(x,y)
   return lcm

def isPowerOfTwo(n): 
    return (math.ceil(Log2(n)) == math.floor(Log2(n))); 
#to check whether the given sorted sequnce is forming an AP or not....
def checkisap(list):
    d=list[1]-list[0]
    for i in range(2,len(list)):
        temp=list[i]-list[i-1]
        if temp !=d:
            return False
    return True
        
    

#ceil  function gives wrong answer after 10^17 so i have to create my own :)
# because i don't want to doubt on my solution of 900-1000 problem set.
def ceildiv(x,y): 
    return (x+y-1)//y 
  
def di():return map(int, input().split())
def ii():return int(input())
def li():return list(map(int, input().split()))
def si():return list(map(int, input()))
def indict():
    dic = {}
    for index, value in enumerate(input().split()):
        dic[int(value)] = int(index)+1
    return dic
def frqdict():
    # by default it is for integer input. :)
    dic={}
    for index, value in enumerate(input().split()):
        if int(value) not in dic:
            dic[int(value)] =1
        else:
            dic[int(value)] +=1
    return dic

#inp = open("input.txt","r")
#out = open("output.txt","w")
#Here we go......................
#practice like your never won
#perform like you never lost
n=ii()
a=li()

if a[0]==0:
    mx=1
    for i in range(1,n):
        if a[i] >mx:
            print(i+1)
            break
        else:
            if a[i]==mx:
                mx+=1

    else:
        print(-1)
else:
    print(1)


            


            
            
            
        
        

    


        
        
        





        
        
        

        

    
            
        
        
    
        
        
        


                
                

    


        
        
    
    
    
        
    
        
    




    

                
    
        


        
    

            
        
    

                
                
                
        
        
        

            

        





                    
                
            
        

            
    
        
    
    

    
        
    
 

    
        


    
        

