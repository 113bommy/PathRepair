import math
n,b=map(int,input().split())
a=list(map(int,input().split()))
oddc,evenc=0,0
diff=list()
for i in range(n-1):
    if a[i]&1:
        oddc+=1
    else:
        evenc+=1
    if oddc==evenc:
        diff.append(math.fabs(a[i]-a[i+1]))
diff.sort()
count=0
i=0
while i<len(diff) and b>=diff[i]:
    b-=diff[i]
    count+=1
    i+=1
print(count)
