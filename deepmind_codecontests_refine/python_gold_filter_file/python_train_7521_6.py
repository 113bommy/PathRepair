def gcd(a,b):
	if b == 0:
		return a
	return gcd(b,a%b)

def lcm(a,b):
	return a*b//gcd(a,b)

def power(a,k,m):
	res = 1
	while k>0:
		if k %2==1:
			res = (res*a)%m
		a = (a*a)%m
		k= k//2
	return res%m

def solution():
	n = int(input())
	arr = list(map(int,input().split()))
	ans = ['a'*arr[0]]
	flag = False
	past = 'a'*arr[0]
	for i in range(1,n):
		st = past[:arr[i-1]] 
		# print(st)
		g = max(arr[i-1],arr[i])
		app = g- len(st)

		if len(past) > arr[i-1] and past[arr[i-1]] == 'a':
			flag = False
		else:
			flag = True
		if flag:
			st = st+'a'*app
		else:
			st = st + 'b'*app
		ans.append(st)
		past = st
		# print(st,flag)
	ans.append(past[:arr[n-1]])

	for i in ans:
		if i == '' and flag:
			flag = False
			print('g')
		elif i == '':
			print('h')
			flag = True
		if i != '':
			print(i)

for i in range(int(input())):
	solution()

