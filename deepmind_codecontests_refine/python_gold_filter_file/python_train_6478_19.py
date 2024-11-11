import math 
n = int(input())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))

count1=0
count2=0

for i in range(n):
    if(l1[i]==1 and l2[i]==0):
        count1+=1
    elif(l1[i]==0 and l2[i]==1):
        count2+=1

if(count1==0):
    print("-1")
else:
    print(math.ceil((count2+1)/count1))