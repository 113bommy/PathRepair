n=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.sort()
p=[(b[i] - a[0])%n[1] for i in range(n[0])]
for i in p:
	s=[(a[j]+i)%n[1] for j in range(n[0])]
	s.sort()
	if(s==b):
		print(i)
		break