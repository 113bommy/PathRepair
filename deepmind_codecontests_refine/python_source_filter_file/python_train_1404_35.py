n,k= map(int,input().split(" "))
l = list(map(int,input().split(" ")))

for i in range(n):
    l[i] = (l[i],i+1)

l.sort()

print(l)

s = 0
ind = 0

while ind<n and s+l[ind][0] <= k:
    s+=l[ind][0]
    ind+=1

#print(ind)
for i in range(ind):
    print(l[i][1],end=" ")



