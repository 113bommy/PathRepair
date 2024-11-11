import math
n,k = map(int,input().split())
factors = [n]
flag=0
# print(len(factors))
while(len(factors)!=k):
    temp = factors.pop()
    # print(temp,end="\n")
    flag=0
    if (temp==2 or temp==3 or temp==5 or temp==7):
        break
    for i in range(2,int(math.sqrt(temp))+1):
        if(temp%i==0):
            flag=1
            factors.append(i)
            factors.append(temp//i)
            break
    if(flag==0):
        break
    # print(*factors)
if(flag==0):
    print(-1)
else:
    print(*factors)           

