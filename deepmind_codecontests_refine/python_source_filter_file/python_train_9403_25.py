'''
#		SHREYANS BHAVSAR	#
#       DDIT				#
#       @shreyans_9950		#
#       CF,CC,HE,HR,GFG		#
'''

# import math
# def shrey():
	# /*!@#$%^&*()-+=*/
	# s=list(input())
	# l=len(s)
	# ans=""
	# for i in range(l):
	# 	if(i==0 or i==l-1 or i%2!=0):
	# 		ans+=s[i]

	# print(ans)
	# n=int(input())
	# a=list(map(int,input().split()))
	# c=0
	# c1=0
	# for i in range(len(a)):
	# 	if(i%2==0 and  a[i]%2!=0):
	# 		c+=1
	# 	if(i%2!=0 and a[i]%2==0):
	# 		c1+=1
	# if(c!=c1):
	# 	print(-1)
	# else:
	# 	print(c)
	# a,b=input().split()
	# a=int(a)
	# b=int(b)
	# ans=(60-b)+((23-a)*60)
	# print(ans)
	# n,k=input().split()
	# n=int(n)
	# k=int(k)
	# print(n-max(0,n%k-k//2))
	# n,k=input().split()
	# n=int(n)
	# k=int(k)
	# for i in range(k):
	# 	if(n%10!=0):
	# 		n-=1
	# 	else:
	# 		n=n//10
	# print(n)

# T = input()
# T = int(T)
# for q in range(1,T+1):
	# /*shreyans bhavsar(DDIT)*/
	# shrey()
# n = int(input())
# str1 = input()
# lst1 = []
# for i in range(n-1):
#     lst1.append(str1[i:i+2])
 
# print (max(lst1,key=lst1.count))
# n,k=input().split()
# n=int(n)
# k=int(k)
# a=list(map(int,input().split()))

# a.sort()
# # print(*a)
# if(k==0):
# 	if(a[0]>1):
# 		print(1)
# 	else:
# 		print(-1)
# else:
# 	if(k==n or a[k]!=a[k-1]):
# 		print(a[k-1])
# 	else:
# 		print(-1)
# for i in range(int(input())):
# 	l,v,u,r=map(int,input().split())
# 	print(l//v-((r//v)-((u-1)//v)))
# for i in range(int(input())):
	# a,b,c=map(int,input().split())
	# ans=max(0,abs(a-b)+abs(a-c)+abs(b-c)-4)
	# print(ans)
# for i in range(int(input())):
# 	n=int(input())
# 	b=3
# 	j=3
# 	while n%b!=0:
# 		b=2**j-1
# 		j+=1
# 	print(n//b)
# for i in range(int(input())):
# 	n=int(input())
# 	if(n%3==0):
# 		print(n//3)
# 	else:
# 		b=3
# 		c=3
# 		while(n%b!=0):
# 			b=2**c-1
# 			c+=1
# 		print(n//b)
# for q in range(int(input())):
# 	n=int(input())
# 	if((n//2)%2!=0):
# 		print("NO")
# 	else:
# 		s=0
# 		s1=0
# 		print("YES")
# 		ans=[]
# 		# ans.append(2)
# 		for i in range(0,n//2):
# 			c=2*(i+1)
# 			s+=c
# 			ans.append(c)
# 		for i in range(n//2,n-1):
# 			c=2*(i-n//2+1)-1
# 			s1+=c
# 			ans.append(c)
# 		d=s-s1
# 		ans.append(d)
# 		print(*ans)
# for q in range(int(input())):
# 	n=int(input())
# 	a=list(map(int,input().split()))
# 	c=0
# 	for i in a:
# 		if i%2!=0:
# 			c+=1
# 	if n==c:
# 		if c%2!=0:
	# 		print("YES")
	# 	else:
	# 		print("NO")
	# elif c>0 and n!=c:
	# 	print("YES")
	# else:
	# 	print("NO")
# import math
# for q in range(int(input())):
# 	n=int(input())
# 	x=(n-1)//9
# 	print(n+x)
# for q in range(int(input())):
# 	n=int(input())
# 	print(1,n-1)
# for q in range(int(input())):
# 	s=int(input())
# 	a=list(map(int,input().split()))
# 	a=set(list(a))
# 	print(len(a))
# t=int(input())
# for p in range (t):
# 	n,x=map(int,input().split())
# 	i=1
# 	ans=['a']*n
# 	while i*(i+1)/2<x:
# 		i+=1
# 	ans[n-i-1]='b'
# 	x=x-i*(i-1)//2
# 	ans[n-x]='b'
# 	print("".join(ans))
# for q in range(int(input())):
# 	n=int(input())
# 	s=list(input())
# 	ans=[]
# 	ans1=[]
# 	f=1
# 	for i in s:
# 		if(f):
# 			if(i=='2'):
# 				ans.append('1')
# 				ans1.append('1')
# 			elif(i=='1'):
# 				# if(f==0):
# 				ans.append('1')
# 				ans1.append('0')
# 				f=0
# 			else:
# 				ans.append('0')
# 				ans1.append('0')
# 		else:
# 			ans.append('0')
# 			ans1.append(i)
# 	ans="".join(ans)
# 	ans1="".join(ans1)
# 	print(ans)
# 	print(ans1)
# for q in range(int(input())):
# 	a,b,n=map(int,input().split())
# 	i=0
# 	while(a<=n and b<=n):
# 		if(a<b):
# 			i+=1
# 			a+=b
# 		else:
# 			i+=1
# 			b+=a
# 	print(i)
# for q in range(int(input())):
import math
# s="codeforces"
# n=int(input())
# if(n==1):
# 	print(s)
# elif(n==2):
# 	s+="s"
# 	print(s)
# elif(n==3):
# 	s+="ss"
# 	print(s)
# else:
# 	t=1
# 	for i in range(2,51):
# 		t2=math.pow(i,10)
# 		t1=t
# 		if n>=t1 and n<=t2:
# 			b=i
# 			break
# 		else:
# 			t=t2
# 	ans=math.pow(b-1,10)
# 	c=0
# 	for i in range(1,11):
# 		c+=1
# 		ans*=b
# 		ans//=(b-1)
# 		if(n<=ans):
# 			break
# 	for i in range(10):
# 		if(i+1<=c):
# 			for j in range(1,b+1):
# 				print(s[i],end="")
# 		else:
# 			for j in range(1,b+1):
# 				print(s[i],end="")
# 	print()
# n = int(input())
# for q in range(n):
# 	s=input()
# 	ans=""
# 	for i in range(len(s)):
# 		if i
# ==0 or i==len(s)-1 or i%2!=0:
# 			ans+=s[i]
# 	ams="".join(ans)
# 	print(ans)
# for i in range(int(input())):
# 	a,b,c,d=map(int,input().split())
# 	if(a*c+b>=d and d%c<=b):
# 		print("YES")
# 	else:
# 		print("NO")
# for q in range(int(input())):
# 	n=int(input())
# 	a=list(map(int,input().split()))
# 	a.sort()
# 	c=1
# 	for i in range(n-1):
# 		if a[i+1]-a[i]==1:
# 			c=2
# 	print(c)
# for q in range(int(input())):
# 	n=int(input())
# 	a=list(map(int,input().split()))
# 	b=sum(a)
# 	a.sort()
# 	if b%n==0:
# 		print(b//n)
# 	else:
# 		print(b//n+1)
# n,k=map(int,input().split())
# a=list(map(int,input().split()))
# aa=[]
# for i in a:
# 	if(i in aa):
# 		continue
# 	if(len(aa)>=k):
# 		aa.pop()
# 	aa.insert(0,i)
# print(len(aa))
# print(*aa)
# n=int(input())
# if(n%2==0 and n>2):
# 	print("YES")
# else:
# 	print("NO")
# import math
# n,m,a=map(int,input().split())
# print(math.ceil(n/a)*math.ceil(m/a))
# for i in range(int(input())):
# 	s=input()
# 	if(len(s)<=10):
# 		print(s)
# 	else:
# 		s=list(s)
# 		n=len(s)
# 		print(s[0],end="")
# 		print(len(s)-2,end="")
# 		print(s[n-1])
n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
for i in a:
	if(i>=a[k-1]):
		c+=1
print(c)