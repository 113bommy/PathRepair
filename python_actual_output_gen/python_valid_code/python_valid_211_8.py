n,l=map(int,input().split())
k=(list(map(int,input().split())))
k.sort()
k1=[k[0],l-k[-1]]
for i in range(1,len(k)):
    k1.append((k[i]-k[i-1])//2)
print(max(k1))
