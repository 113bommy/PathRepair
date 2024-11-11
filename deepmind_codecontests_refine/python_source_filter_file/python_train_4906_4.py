n=int(input())
a=list(map(int,input().split()))
l=[]
for i in range(n):
	l.append([a[i],i])
l.sort(key=lambda x:x[0])
for i in range(n):
    if l[i][0]>1:
        break
j=0
for k in range(i,n):
    j+=l[k][0]-2
if j<i-2:
    print("NO")
else:
	print("YES",n-i+min(2,i))
	print(n-1)
	k=2
	for j in range(i,n-1):
	    print(l[j][1]+1,l[j+1][1]+1)
	if i>0:
		print(l[0][1]+1,l[i][1]+1)
	if i>1:
		print(l[1][1]+1,l[n-1][1]+1)
	if i>2:
		for j in range(i,n):
			if k==i:
				break
			for p in range(2,l[j][0]):
				print(l[k][1]+1,l[j][1]+1)
				k+=1
				if k==i:
					break
