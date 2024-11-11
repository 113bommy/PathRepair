from collections import defaultdict
n = int(input())
if(n==1):
    print(input())
else:
    d = defaultdict(int)
    s = set()
    for _ in range(n):
        x = input()
        d[x]+=1
        s.add(x)
    mx = -1
    ans = ''
    for i in x:
        if(d[i]>mx):
            mx = d[i]
            ans = i
    print(ans)