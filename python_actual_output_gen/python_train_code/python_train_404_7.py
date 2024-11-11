n=int(input())
a=list(map(int,input().split()))
s=a[0]
for i in range(1,len(a)):
	s=s+(a[i]-1)+a[i]
print(s)