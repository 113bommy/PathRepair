import sys,os,io
from collections import defaultdict
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range (int(input())):
    n,x = [int(i) for i in input().split()]
    dic = defaultdict(lambda: 0)
    s = input()
    cnt = 0
    zero = 0
    mini = 10**10
    maxi = -10**10
    for i in s:
        if i=='0':
            cnt+=1
        else:
            cnt-=1
        dic[cnt]+=1
        if cnt==0:
            zero+=1
        mini = min(mini,cnt)
        maxi = max(maxi,cnt)
    last = 0
    if cnt==0:
        if x in dic:
            print(-1)
        else:
            print(0)
    elif cnt>0:
        ans = 0
        mm = (x-maxi)//cnt
        if mm>0:
            mm-=1
            last = mm*cnt
        while(last+mini)<=x:
            if (x-last) in dic:
                ans+=dic[x-last]
            last+=cnt
        if x==0:
            ans+=1
        print(ans)
    else:
        ans = 0
        mm = (abs(x)-abs(mini))//abs(cnt)
        if mm>1:
            mm = abs(mm)-2
            last = mm*cnt
        while(last + maxi) >= x:
            if (x-last) in dic:
                ans+=dic[x-last]
            last += cnt
        if x==0:
            ans+=1
        print(ans)