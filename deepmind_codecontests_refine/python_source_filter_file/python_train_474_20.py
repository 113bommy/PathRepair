import math

n,k = map(int, input().split())
l = list(map(int, input().split()))

#l.sort()
nbr_days=0

for i in range(n-1):
	if(l[i]>0):
		t=math.ceil(l[i]/k)
		nbr_days += t
		l[i+1] -= t*k 

if(l[n-1]>0):
	t = math.ceil(l[n-1]/(2*k))
	nbr_days += t

print(nbr_days, end="")