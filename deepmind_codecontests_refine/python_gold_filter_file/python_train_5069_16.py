n,b=input().strip().split()

n,b=int(n),int(b)
cuts=[]
a=[int(_) for _ in input().strip().split()]
odd=0
even=0
for i in range(len(a)-1):
	if a[i]%2==0:
		even+=1
	else:
		odd+=1
	if (odd == even):
		cuts.append(abs(a[i+1]-a[i]))

cuts.sort()
ans=0
for i in cuts:
	if b-i>=0:
		b-=i
		ans+=1
	else:
		break
print(ans)