n,d=map(int,input().split())
A=list(map(int,input().split()))
a={i+1:A[i] for i in range(n-1)}
i=1
while(i<=d):
	if(i==d):
		print("YES")
		break
	else:
		i+=a[i]
else:
	print("NO")
