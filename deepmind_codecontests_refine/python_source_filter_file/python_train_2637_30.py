import math
t=int(input())
arr=list(map(int,input().split()))
count=[0]*5
for x in arr:
    count[x]=count[x]+1
#print(count)
result=0
result=result+count[4]
count[4]=0
result=result+count[3]
count[1]=count[1]-count[3]
count[3]=0
a=count[2]*2+max(count[1],0)
b=a//4
result=result+b
#print(b)

print(result)
