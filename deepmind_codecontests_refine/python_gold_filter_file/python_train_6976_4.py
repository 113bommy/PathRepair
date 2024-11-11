n = int(input())
*bLst, = input().split()
iLst = bLst[:]

for i in range(n):
    for j in range(n-1,i,-1):
        if bLst[j][1] < bLst[j-1][1]:
            bLst[j],bLst[j-1] = bLst[j-1],bLst[j]

print(*bLst)
print("Stable")

for i in range(n):
    min = i
    for j in range(i,n):
        if iLst[j][1] < iLst[min][1]:
            min = j
    iLst[i],iLst[min] = iLst[min],iLst[i]

print(*iLst)
if bLst == iLst:
    print("Stable")
else:
    print("Not stable")
