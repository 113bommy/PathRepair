n=int(input())
lst=list(map(int,input().split()))
mas,length=[],0
for i,x in enumerate(lst):
    if x==0:mas.append(i);length+=1
from bisect import bisect
res=[]
for i,x in enumerate(lst):
    if x==0:res.append(0)
    else:
        a=bisect(mas,i)
        if a==0:res.append(mas[0]-i)
        elif a==length:res.append(i-mas[length-1])
        else:res.append(min(i-mas[a-1],mas[a]-i))
print(*res)