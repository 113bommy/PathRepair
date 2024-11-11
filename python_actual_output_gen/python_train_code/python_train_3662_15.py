n=int(input())
a=list(map(int,input().split()))
m=sorted(a,reverse=True)
print(m)
j=[]
for i in a:
	k=m.index(i)
	j.append(k+1)

print(*j)