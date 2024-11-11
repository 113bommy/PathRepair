from math import pi as p
n=int(input());l=list(map(int,input().split()));l.sort();a=0;s=1 if n%2 else 0
for i in range(s,n-1,2):
	a+=abs(l[i]*l[i]-l[i+1]*l[i+1])
if n%2:a+=l[0]
print(a*p)