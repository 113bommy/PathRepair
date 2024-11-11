n,m = list(map(int,input().split()))
arr1 = list(map(int,input().split()))
arr2 = list(map(int,input().split()))
d = {}
for i in arr2:
    d[i] = 0
temp1 = arr1[::]
temp2 = arr2[::]
temp1.sort()
temp2.sort()
ind1,ind2 = 0,0
while True:
    if temp2[ind2]>=temp1[ind1]:
        ind1+=1
    else:
        d[temp2[ind2]]=ind1
        ind2+=1
    if ind1>=n or ind2>=m:
        break
for i in range(ind2,m):
    d[temp2[ind2]] = ind1
for i in arr2:
    print(d[i],end=" ")