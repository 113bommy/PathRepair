# template begins
#####################################
 
# import libraries for input/ output handling
# on generic level
import atexit, io, sys, math, heapq

#input handling
#input of single integer
def get_int(): return int(sys.stdin.readline().strip())
#input of multiple integers
def get_ints(): return map(int, sys.stdin.readline().strip().split())
#input of list
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
#input of string
def get_string(): return sys.stdin.readline().strip()

#output handling
#writing int output
def write_int(a): sys.stdout.write(str(a)+"\n")
#writing String
def write_str(a): sys.stdout.write(a+"\n")
#writing Array
def write_list(arr): sys.stdout.write(" ".join(map(str, arr)) + "\n")

#general functions
#swap
def swap(arr, a, b):
	arr[a]^=arr[b]
	arr[b]^=arr[a]
	arr[a]^=arr[b]

#NumberOfDigits
def int_len(a): return math.floor(math.log(a,10))+1

#Powerof2
def isPowerOfTwo(x): return x and (not(x & (x-1)))

#Sieve
def Sieve(n):
	prime = [True for i in range(n+1)]
	p = 2
	while (p * p <= n):
		if (prime[p] == True):
			for i in range(p * p, n+1, p):
				prime[i] = False
		p += 1
	res = []
	for i in range(2,len(prime)):
		if (prime[i]):
			res.append(i)
	return res

#binarySearch
def binarySearch (arr, l, r, x):
	if r >= l:
  
		mid = l + (r - l) // 2
		if arr[mid] == x:
			return mid
		elif arr[mid] > x:
			return binarySearch(arr, l, mid-1, x)
		else:
			return binarySearch(arr, mid + 1, r, x)
	else:
		return -1
def search(arr,x):
	return binarySearch(arr,0,len(arr)-1,x)

#Array to String
def toString(A):
	return''.join(A)

#ArraySum
def arrSum(Arr):
	Sum =0
	for i in range (len(Arr)):
		Sum+=Arr[i]
	return Sum

#####################################
# template ends

# Code begins
#####################################

def compare(_from, _to):
	steps = 0
	i = 0
	j = 0
	while i < len(_from) and j< len(_to):
		if _from[i] != _to[j]:
			steps+=1
		else:
			i+=1
		j+=1
	return steps + len(_to)+len(_from)-i-j
arr = [0]*40
j = 0
while (j<40):
	arr[j] = 2**j
	j+=1

p = int(input())

while p>0:
 	N = input()
 	min = 99999999
 	for i in range (len(arr)):
 		res= compare(str(arr[i]),N)
 		if (res < min):
 			min = res
 	print (min)



 	p-=1


#####################################
# Code ends


# Creating 2D array sol = [[0 for i in range(N)] for j in range(N)]