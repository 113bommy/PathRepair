t=int(input())
num=[int(x) for x in input().split()]
ones=num.count(1)
delta=[]
for i in range(t):
	for j in range(i+1,t+1):
		delta.append(2*num[i:j].count(0)-(j-i))
delta.sort()
print(ones+delta[-1])
