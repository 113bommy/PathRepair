import math
n=int(input())
t=list(map(int,input().split()))
maxl=0
add=0
for i in t:
	maxl=max(maxl,i)
	add+=i
	
print(max(math.ceil(add*2/n),maxl))
