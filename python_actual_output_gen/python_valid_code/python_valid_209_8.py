n,p,k=map(int,(input().split()))
if p-k>=1:
	print("<<",end=" ")
for i in range(p-k,p+k+1):
	if i>n:
			pass
	elif i==0:
		continue
	elif i==p:
		print(f"({i})",end=" ")
	else:
		if i==p+k:
			print(i,end=" ")
		else:
			print(i,end=" ")
if p+k<n:
		print(">>",end="")