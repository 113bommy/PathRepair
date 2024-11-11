l=int(input())
for i in range(1,20):
	if 2**i>l:
		r=i-1
		break
ans=[]
for i in range(r):
	ans.append((i+1,i+2,0))
	ans.append((i+1,i+2,2**i))
now=2**r-1
for i in range(r,0,-1):
	if 2**(i-1)+now<=l-1:
		ans.append((i,r+1,now+1))
		now+=2**(i-1)
print(r+1,len(ans))
for x in ans:
	print(*x)