t=int(input())
num=[int(x) for x in input().split()]
ones=num.count(1)
delta=[0]
for i in range(t-1):
	for j in range(i,t):
		delta.append(2*num[i:j].count(0)-(j-i))
delta.sort()
print(ones+delta[-1])