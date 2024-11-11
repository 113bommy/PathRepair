x=int(input())
y=input().split()
y=list(map(int, y))

y.sort()
sums=[]

for i in range(len(y)-1):
    for j in range(i+1,len(y)):
        sums.append(y[i]+y[j])
        
    
count=0
maxcount=0

sums=(sorted(sums))

for i in range(len(sums)-1):
    if sums[i]==sums[i+1]:
        count+=1
        if count>maxcount:
            maxcount=count
    else:
        count=0
print(maxcount+1)

