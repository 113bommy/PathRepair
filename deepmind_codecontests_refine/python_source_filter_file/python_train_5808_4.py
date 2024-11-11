def solve():
    ans = []
    for x, y in s:
        if(num[x]>num[y]): x, y = y, x
        num[x]+=1
        num[y]-=1
        ans.append(x)
        if num[y]<0: return False
    return ans
from collections import defaultdict
import sys
n, a, b, c = map(int, input().split())
num = defaultdict(int)
s = [input() for _ in range(n)]
num['A'] = a
num['B'] = b
num['C'] = c
id = ['A', 'B', 'C']
id.sort(key = lambda x:num[x])
if a+b+c == 0:
    print('No')
    sys.exit()
elif a+b+c == 1:
    ans = solve()
    if ans: 
        print('Yes')
        print(*ans, sep = '\n')
    else:
        print('No')
elif a+b+c == 2:
    ans = []
    flag = True
    for i, (x, y) in enumerate(s):
        if num[x]>num[y]: x, y = y, x
        if num[x]==num[y] and i < n-1:
            if y == s[i+1][0] or y == s[i+1][1]:
                x, y = y, x
        num[x]+=1
        num[y]-=1
        ans.append(x)
        if num[y]<0:
            flag = False
    if flag:
        print('Yes')
        print(*ans, sep = '\n')
    else:
        print('No')
elif num[id[0]] == 0 and num[id[1]] == 0 and (s[i]==id[0]+id[1] or [i]==id[1]+id[0]):
    print('No')
else:
    ans = solve()
    print('Yes')
    print(*ans, sep = '\n')
     



