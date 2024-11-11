
na,mb=map(int,input().split())
k,m=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
note=len(l2)
for i in range (len(l2)):
	if l1[k-1]<l2[i]:
		note=i
		break
if len(l2)-note>m:
	print("YES")
else:
	print("NO")