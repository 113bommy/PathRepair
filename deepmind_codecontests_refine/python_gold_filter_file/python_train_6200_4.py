from math import ceil
from math import floor	
from math import sqrt
from math import log

prime = pow(10, 9) + 7

def mod_expo(n, p, m):
	"""find (n^p)%m"""
	result = 1
	while p != 0:
		if p%2 == 1:
			result = (result * n)%m
		p //= 2
		n = (n * n)%m
	return result
	
def get_count_pairs(n, X, arr):
	count = 0
	mp = {}
	for i in range(n):
		if arr[i] not in mp:
			mp[arr[i]] = 0
		mp[arr[i]] += 1
	
	if X == 0:
		arr = set(arr)
		arr = list(arr)
		n = len(arr)	
	for i in range(n):
		exor = arr[i] ^ X
		if exor in mp:
			if X == 0:
				count += int((mp[exor]*(mp[exor] - 1))/2)
			else:
				count += mp[exor] 
	if X > 0:
		count //= 2;
	return count
	
def check(n, k):
	v = 0
	left = n
	while left > 0:
		current = min(left, k)
		v += current
		left -= current
		left -= left//10
	return (2*v >= n)	
	
def get_pair_count(n, arr):
	count = 0
	mp = {}
	for i in range(n):
		if arr[i] not in mp:
			mp[arr[i]] = 0
		mp[arr[i]] += 1 
	for i in range(n):
		for deg in range(1, 31):
			val = pow(2, deg) - arr[i] 
			if val in mp:
				count += mp[val]
				if val == arr[i]:
					count -= 1
		mp[arr[i]] -= 1
				
	return count

def find_bsearch(n):
	left = 1
	right = n
	middle = 0
	if n <= 2:
		return 1
	while left < right:
		#if (middle == int((left + right)/2)):
		#	right = middle
		middle = left + (right - left)//2
		#print(left, middle, right)
		if check(n, middle):
			if middle == left or not check(n, middle-1):
				return middle
			right = middle-1
		else:
			left = middle+1
	return left	
		
def find_divisors(x):
	divisors = []
	for i in range(2, int(sqrt(x))+1):
		if x%i == 0:
			if x == i * i:
				divisors.append(i)
			else:
				divisors.append(i)
				divisors.append(int(x/i))
	
	return divisors

def find_min(N, d):
	N = str(N)
	d = str(d)
	for i in range(len(N)-1, -1):
		print(N[i])
		if int(N[i]) > int(d):
			N = ''.join([N[j] for j in range(len(N)) and j != i])
			N += d
	return N  

t=1
# t=int(input())
while t:
	t = t - 1
	count=0
	#n, m, x, y = map(int, input().split())
	# n, X = map(int, input().split())
	# text = input()
	n = int(input())
	arr = list(map(int, input().strip().split()))[:n]
	# b = list(map(int, input().strip().split()))[:n]
	#N = input()
	# below = input()
	print(get_pair_count(n, arr))

	#n, X = map(int, input().split())
	#a2, b2 = map(int, input().split())
	
	# print(a + g)
	
	# print(ffin(n, arr, b))
	#if is_possible(n, m , x, y):
	 #	print("Chefirnemo")
	#else:
	#	print("Pofik")
	#answers = find_given_gcd(n, k)

	
