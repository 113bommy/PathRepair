n=int(input())
b=list(map(int,input().split()))
s=b[0]
for i in range(n-1):
	s=s+abs(b[i]-b[i+1])
print(s)