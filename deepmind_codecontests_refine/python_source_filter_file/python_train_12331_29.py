import math
a=list(map(int,input().split()))
b=list(map(int,input().split()))
suma=sum(a)
sumb=sum(b)
n=int(input())
x=math.ceil(suma/5)
y=math.ceil(sumb/10)
shel=x+y
if n>=shel:
	print("Yes")
else:
	print("NO")
