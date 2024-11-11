r = lambda : map(int,input().split())

import sys
n = int(input())
s = input()
q = set()
if n>len(set(s)) :
    print('NO')
else :
    print('YES')
    k = 0
    ans = []
    for i in range(len(s)) :
        if k==n : break
        if s[i] not in q :
            ans.append(i)
            q.add(s[i])
            k+=1
    ans.append(len(s))
    for i in range(len(ans)-1) :
        print(s[ans[i]:ans[i+1]])
                
