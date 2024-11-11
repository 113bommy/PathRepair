from collections import defaultdict
from _bisect import bisect_right

s,t=input(),input()
m=len(s)

if set(s)&set(t)!=set(t):print(-1);exit()

dict=defaultdict(list)
for i,j in enumerate(s):
    dict[j] +=[i+1]

ans,index=0,0
for i in t:
    point=bisect_right(dict[i],index)
    if point==len(dict[i]):num=dict[i][0]
    else:num=dict[i][point]

    if index>num:
        ans +=m
    index=num
    
print(ans+index)