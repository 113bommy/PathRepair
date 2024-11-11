p=input
n,m=map(int,p().split())
l=[p().split()for _ in[0]*n]
print(max([sum(sorted([sum([int(x[i])*[1,-1][k>>i&1]for i in range(3)])for x in l])[-m:])for k in range(8)]))