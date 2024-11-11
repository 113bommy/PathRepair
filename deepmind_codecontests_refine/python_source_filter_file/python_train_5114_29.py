import math
def lis() : return list(map(int,input().split()))
x=int(input())
lst=list(map(int,input().split()))
y=0
for j in range(x-1):
    if(lst[j+1]==1 and lst[j-1]==1 and lst[j]==0):
        #print(j)
        lst[j+1]=0
        y+=1
print(y)


