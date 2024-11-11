"""n=int(input())
a=list(map(int,input().split()))
ct=[0]*20
for x in a:
	for sf in range(20):
		ct[sf]+=(x>>sf)&1
ans=[0]*n
for i in range(20):
	for j in range(ct[i]):
		print(ans[j],1<<i,ans[j] | 1<<i)
		ans[j]|=1<<i		
print(sum([x**2 for x in ans]))
"""

"""k=int(input())
s='codeforces'
i,sm=0,1
l=[1]*10
while sm<k:
	
	sm//=l[i]
	print(sm,l[i])
	l[i]+=1
	print(l[i])
	sm*=l[i]
	print(sm)
	i=(i+1)%10
print(l)
ans=[s[i]*l[i] for i in range(10)]
print(''.join(ans))"""


"""T =int(input())
for _ in range(T):
	a=input()
	if len(a)==2:
		print(a)
	else:
		for i in range(0,len(a),2):
			print(a[i],end="")
		print(a[-1])"""

"""T = int(input())
for _ in range(T):
	n = int(input())
	arr = list(map(int,input().split()))
	a=b=0
	for i in range(n):
		if i%2 != arr[i]%2:
			if i%2==0:
				a+=1
			else:
				b+=1
	if a==b:
		print(a)
	else:
		print(-1)"""

"""T= int(input())
for _ in range(T):
	n,k = list(map(int,input().split()))
	a = input()
	e='0'*k+a+'0'*k
	f = k*2+1
	z=ct=0
	for i in e.split('1'):
		ct+=max((len(i)-k)//(k+1),0)
	print(ct)"""

"""for _ in range(int(input())):
	arr = ['#']+sorted(list(input()))
	n = int(input())
	num = [-1]+[int(i) for i in input().split()]
	ans = ['#']*(n+1)
	while 0 in num:
		zero = []
		for i in range(1,n+1):
			if num[i]==0:
				zero.append(i)
				num[i]=-1
		#print("zero",zero)
		while arr.count(arr[-1])<len(zero):
			p = arr[-1]
			while p==arr[-1]:
				arr.pop()
		#print("arr",arr)
		p=0
		for i in zero:
			p=ans[i]=arr[-1]
		#print("ans",ans)
		while arr[-1]==p:
			arr.pop()
		for i in range(1,n+1):
			if ans[i]=='#':
				for j in zero:
					num[i]-=abs(j-i)
				#print("num",num)
	print(''.join(ans[1:]))"""

import math
import collections
for _ in range(int(input())):
    n,k = map(int, input().split())
    s = input()
    ctr = collections.Counter(s) 
    ans = 0
    for i in range(1,n+1):
        g = math.gcd(i, k)
        l = i // g
        #print(i,k,g,l)
        cnt = sum([(v//l)*l for v in ctr.values()])
        #print(cnt)
        if cnt >= i:
            ans = i
    print(ans)