import bisect
from collections import OrderedDict
a,b=list(map(int,input().split()))
aray=list(map(int,input().split()))
dic={}
ans=OrderedDict()
max=0
min=555555
summ=0
arr=[]
answer=[]
for x in range(b):
    c,d=list(map(int,input().split()))
    if c not in dic:
       dic[c]=[d]
       arr.append(c)
    else:
        dic[c].append(d)
    if c>max:
        max=c
    if c<min:
        min=c
arr.sort()
for it in arr:
    summ+=sum(dic[it])
    ans[it]=summ
for it in aray:
    if it in ans:
        answer.append(ans[it])
    else:
        if it<min:
            answer.append(0)
        elif it>=max:
            answer.append(ans[max])
        else:
            ind = bisect.bisect_left(arr,it)
            answer.append(ans[arr[ind-1]])
print(*answer)