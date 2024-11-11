# s = 'dic = {'
# c = 0
# for i in range(ord('A'),ord('X')):
# 	if chr(i) not in ['B','J','O','U']:
# 		s+= "'" + chr(i) + "':" + str(c) + ","
# 		c+=1
# s+="'" + 'Y' + "':" + str(c) + ","
# c+=1
# s+="'" + 'X' + "':" + str(c) + ","
# c = 0
# for i in range(ord('a'),ord('x')):
# 	if chr(i) not in ['b','j','o','u']:
# 		s+= "'" + chr(i) + "':" + str(c) + ","
# 		c+=1
# s+="'" + 'y' + "':" + str(c) + ","
# c+=1
# s+="'" + 'x' + "':" + str(c) + " }"
# print(s)
# n = int(input())
# b = list(map(int,input().split()))
# m = int(input())
# g = list(map(int,input().split()))
# c = 0
# b.sort()
# g.sort()
# t = [False]*m
# for i in range(n):
# 	for j in range(m):
# 		if abs(b[i]-g[j])<=1:
# 			c+=1
# 			g[j] = -500
# 			break
# print(c)
# a = list(input())
# b = list(input())
# a.sort()
# b.sort()
# print(a,b)
# x,y = 0,0
# if a>b:
# 	print(1)
# elif a<b:
# 	print(2)
# else:
# 	print(3)
# for i in range(len(a)):
# 	if ord(a[i])>ord(b[i]):
# 		x+=1
# 	elif ord(a[i])<ord(b[i]):
# 		y+=1
# 	else:
# 		x+=1
# 		y+=1
# 	print(x,y)
# if x>y:
# 	print('Wakanda')
# elif y>x:
# 	print('Kree')
# else:
# 	print('Tie')



# arr = [1]
# x = 1
# while x<=10**18:
# 	x*=2
# 	arr.append(x)
# print(arr)

# for _ in range(int(input())):
# 	p = list(map(int,input().split()))
# 	a = list(map(int,input().split()))
# 	diff = [a[0]-p[0],a[1]-p[1],a[2]-p[2]]
# 	mult = [-1]*3
# 	for i in range(3):
# 		if a[i]%p[i]==0:
# 			mult[i] = a[i]//p[i]
# 	if diff[0]==diff[1]==diff[2]:
# 		if diff[0]==0:
# 			print(0)
# 		else:
# 			print(1)
# 	elif mult[0]==mult[1]==mult[2]!=-1:
# 		print(1)
# 	elif diff[0]==diff[1]:
# 		if diff[0]==0 or diff[2]==0:
# 			print(1)
# 		else:
# 			print(2)
# 	elif diff[0]==diff[2]:
# 		if diff[0]==0 or diff[1]==0:
# 			print(1)
# 		else:
# 			print(2)
# 	elif diff[1]==diff[2]:
# 		if diff[1]==0 or diff[0]==0:
# 			print(1)
# 		else:
# 			print(2)
# 	elif mult[0]==mult[1]!=-1 or mult[0]==mult[2]!=-1 or mult[1]==mult[0]!=-1  or mult[1]==mult[2]!=-1  or mult[2]==mult[0]!=-1  or mult[2]==mult[1]!=-1 :
# 		print(2)
# 	elif (mult[0]*mult[1]==mult[2] and mult[0]!=-1 and mult[1]!=-1 and mult[2]!=-1) or (mult[1]*mult[2]==mult[0] and mult[0]!=-1 and mult[1]!=-1 and mult[2]!=-1) or (mult[0]*mult[2]==mult[1] and mult[0]!=-1 and mult[1]!=-1 and mult[2]!=-1):
# 		print(2)   
# 	elif a[0]%p[0]==a[1]%p[1] and a[0]%(a[0]%p[0]+p[0])==0 and a[1]%(a[1]%p[1]+p[1])==0 and a[2]%p[2]==0 and a[0]//(a[0]%p[0]+p[0])==a[1]%(a[1]%p[1]+p[1]):
# 		if a[2]==p[2] or a[2]//p[2]==a[0]//(a[0]%p[0]+p[0]):
# 			print(2)
# 	elif a[0]%p[0]==a[2]%p[2] and a[0]%(a[0]%p[0]+p[0])==0 and a[2]%(a[2]%p[2]+p[2])==0 and a[1]%p[1]==0 and a[0]//(a[0]%p[0]+p[0])==a[2]%(a[2]%p[2]+p[2]):
# 		if a[1]==p[1] or a[1]//p[1]==a[0]//(a[0]%p[0]+p[0]):
# 			print(2)
# 	elif a[2]%p[2]==a[1]%p[1] and a[2]%(a[2]%p[2]+p[2])==0 and a[1]%(a[1]%p[1]+p[1])==0 and a[0]%p[0]==0 and a[2]//(a[2]%p[2]+p[2])==a[1]%(a[1]%p[1]+p[1]):
# 		if a[0]==p[0] or a[0]//p[0]==a[2]//(a[2]%p[2]+p[2]):
# 			print(2)
# 	elif a[0]//p[0]==a[1]//p[1] and a[0]-(a[0]//p[0])*p[0] == a[1]-(a[1]//p[1])*p[1] == a[2]-p[2]:
# 		if a[2]==p[2]:
# 			print(1)
# 		else:
# 			print(2)
# 	elif a[0]//p[0]==a[2]//p[2] and a[0]-(a[0]//p[0])*p[0] == a[2]-(a[2]//p[2])*p[2] == a[1]-p[1]:
# 		if a[1]==p[1]:
# 			print(1)
# 		else:
# 			print(2)
# 	elif a[2]//p[2]==a[1]//p[1] and a[2]-(a[2]//p[2])*p[2] == a[1]-(a[1]//p[1])*p[1] == a[0]-p[0]:
# 		if a[0]==p[0]:
# 			print(1)
# 		else:
# 			print(2)
# 	elif a[0]==a[1]==a[2] and p[0]==p[1]!=p[2] or p[0]==p[2]!=p[1] or p[0]!=p[1]==p[2] or p[0]!=p[1]!=p[2]:
# 		print(2)
# 	else:
# 		print(3)

# def binsearch(arr,x):
# 	n = len(arr)
# 	if n==0:
# 		return False
# 	if n==1:
# 		return x==arr[0]
# 	else:
# 		mid = arr[n//2]
# 		if mid==x:
# 			return True
# 		else:
# 			if mid>x:
# 				return binsearch(arr[:n//2],x)
# 			else:
# 				return binsearch(arr[n//2+1:],x)

#Sieve (all prime numbers till n)
# n = 10**6
# l = [i for i in range(2,n+1)]
# l = [0,1] + l
# p = 2
# t = [False]*len(l)
# while p**2<=n:
# 	if not t[p]:
# 		for i in range(p**2, n+1,p):
# 			t[i] = True
# 	p+=1
# primes = [i for i in range(len(t)) if not t[i]]
# primes.pop(0)
# primes.pop(0)
# print(primes)
#Sieve (least prime factor of a number)
# least = [0]*(n+1)
# least[1] = 1
# for i in range(2,n+1):
# 	if not least[i] :
# 		least[i] = i
# 		for j in range(2*i,n+1,i):
# 			if not least[j] :
# 				least[j] = i

# print(least)
#Sieve (prime factorization)
# def pf(x):
# 	r = []
# 	while x!=1:
# 		r.append(least[x])
# 		x//=least[x]
# 	return r


#Efficient power(x,n)
# def pow(x,n):
# 	if n==0:
# 		return 1
# 	p = pow(x,n//2)
# 	if n%2==0:
# 		return p*p
# 	else:
# 		return x*p*p
# x,n = map(int,input().split())
# ans = pow(x,abs(n))
# if n<0:
# 	print(1/ans)
# else:
# 	print(ans)
n,l = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
a = a
maxx = 0
# print(a)
for i in range(1,len(a)-1):
	maxx = max(maxx,a[i]-a[i-1])
# print(maxx)
print(max(maxx/2,a[0],l-a[-1]))

