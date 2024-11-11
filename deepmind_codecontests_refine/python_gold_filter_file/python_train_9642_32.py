n=int(input())
a=input()
counti,countj=0,0
for i in range(0,1):
    for j in range(0,n-1):
        if a[j]=="S" and a[j+1]=="F":
            counti += 1
        elif a[j]=="F" and a[j+1]=="S":
            countj += 1
if counti>countj:
    print("YES")
    exit()


print("NO")