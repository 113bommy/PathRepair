n = int(input())
l = list(map(int,input().split()))
total,flag = 0,0
for j in range(1,n):
    x = l[j]
    y = l[j-1]
    if((x,y)==(1,2) or (x,y)==(2,1)):
        total+=3
    elif((x,y)==(1,3) or (x,y)==(3,1)):
        total+=4
    else:
        flag = 1
        break
    if(j>=2 and ((l[j],l[j-1],l[j-2])==(2,1,3))):
        total+=1
if(flag==1):
    print("Infinite")
else:
    print("Finite")
    print(total)