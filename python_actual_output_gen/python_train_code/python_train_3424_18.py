a=input().split()
fences=int(a[0])
minFences=int(a[1])
fenceList=input().split()
total=0
out=0
for i in range(fences):
    fenceList[i]=int(fenceList[i])
for i in range(minFences):
    out+=fenceList[i]
total=out
start=0
for i in range(minFences,fences):
    total-=fenceList[i-minFences]
    total+=fenceList[i]
    if total<out:
        out=total
        start=i-minFences+2
print(start)
