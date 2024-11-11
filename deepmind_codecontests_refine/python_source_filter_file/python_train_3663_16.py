q=int(input())
l=list(map(int,input().split(" ")))

cnt=0
d=[]
sum1=0
c=[]

for i in range(q):
	d.append((l[i],i))
	# d.update({l[i]:i})

d.sort()
d=d[::-1]
print(d)

for i in range(len(d)):
	c.append(d[i][1]+1)
	sum1=sum1+d[i][0]*cnt+1
	cnt=cnt+1

# print(d)

print(sum1)
for i in c:
	print(i,end=" ")

print()