n,l,r=map(int,input().split())

mi=[]
ma=[]

for i in range(l):
    mi.append(2**i)
for i in range(r):
    ma.append(2**i)

minSum=min(mi)*(n-l)+sum(mi)
maxSum=max(mi)*(n-r)+sum(ma)

print(minSum,maxSum)