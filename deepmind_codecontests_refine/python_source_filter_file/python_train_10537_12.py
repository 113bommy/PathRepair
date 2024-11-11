def Input():
    ans = []
    tem = input().split()
    for it in tem:
        ans.append(int(it))
    return ans
from collections import Counter
T = Input()[0]
for tt in range(T):
    s = input()
    t = input()
    s_map = Counter(s)
    t_map = Counter(t)
    flag = False
    for it in t_map.keys():
        if it not in s_map.keys():
            flag = True
            print(-1)
            break
    if flag:
        continue
    n = len(s)
    m = len(t)
    ma = {}
    for i in range(n):
        if s[i] not in ma.keys():
            ma[s[i]] = [i]
        else:
            ma[s[i]].append(i)
    ans = 0
    i = 0
    p = -1
    while i<m:
        if p==-1:
            ans+=1
            lis = ma[t[i]]
            p = lis[0]
            i+=1
        else:
            lis = ma[t[i]]
            l, r = 0, len(lis)-1
            while l<r:
                mid = (l+r)//2
                if lis[mid]<p:
                    l = mid+1
                else:
                    r = mid
            if lis[l]>p:
                p = lis[l]
                i+=1
            else:
                p = -1
    print(ans)
                
        
                