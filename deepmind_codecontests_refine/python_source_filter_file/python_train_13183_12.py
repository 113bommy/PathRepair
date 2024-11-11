#########################################################################################################\
#########################################################################################################
###################################The_Apurv_Rathore#####################################################
#########################################################################################################
#########################################################################################################

import sys,os,io
from math import log, gcd, ceil
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop
from bisect import bisect_right , bisect_left

import math 



def ncr(n, r, p):  #using fermat's little theorem
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

  
def primeFactors(n): 
    l = []
    while n % 2 == 0: 
        l.append(2)
        n = n / 2
          
    for i in range(3,int(math.sqrt(n))+1,2): 
          

        while n % i== 0: 
            l.append(int(i))
            n = n / i 
    if n > 2: 
        l.append(n)
    return list(set(l))
    
def power(x, y, p) : 
	res = 1
	x = x % p 
	if (x == 0) : 
		return 0
	while (y > 0) : 
		if ((y & 1) == 1) : 
			res = (res * x) % p 
		y = y >> 1	 # y = y/2 
		x = (x * x) % p 		
	return res 


def si():
    return input()


def prefix_sum(arr):
    r = [0] * (len(arr)+1)
    for i, el in enumerate(arr):
        r[i+1] = r[i] + el
    return r

def divideCeil(n,x):
    if (n%x==0):
        return n//x
    return n//x+1

def ii():
    return int(input())

def li():
    return list(map(int,input().split()))

def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')


if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
# t = int(input())
t = 1
for _ in range(t):
    a = input()
    b = input()
    ans = [a]
    a = list(a)
    b1 = b[:]
    b = list(b)
    if (len(a)<len(b)):
        a.sort(reverse=True)
        print(''.join(a))
        continue
    arr = [0]*10
    for i in a:
        arr[int(i)]+=1
    f = 0
    for chota in range(len(b)):
        arr1 = arr[:]
        temp = b[:chota]

        for h in range(chota):
            if (arr1[int(b[h])]<=0):
                f = 1
                break
            else:
                arr1[int(b[h])]-=1
        
            #print(f)
        if (f==1):
            break
        aa = []
        for j in range(int(b[chota])-1,-1,-1):

            if (arr1[j]>0):
                temp.append(str(j))
                arr1[j]-=1
                break
        for h in range(9,-1,-1):
            if (arr1[h]>0):
                temp+=[str(h)]*arr1[h]
        #print(temp)
        ans.append(''.join(temp))
        
            #print("yes",temp)
    for i in ans:
        if (i<b1):
            m = i
            break 
    a.sort(reverse=True)
    ans.append(''.join(a))
    # print(ans)
    for i in ans:
        if (i<b1):
            if (i>m):
                m = i
    print(m)



    