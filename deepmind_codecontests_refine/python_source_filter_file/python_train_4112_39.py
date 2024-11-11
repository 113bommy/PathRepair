import math
N = int(input())

i = 1
ans = 0
while(i<N):
	if(i*10<=N):
		ans+=(math.floor(math.log10(i))+1)*(i*10-i)
		i *= 10
	else:
		ans+=(math.floor(math.log10(i))+1)*(N-i+1)
		i = N
print (ans)