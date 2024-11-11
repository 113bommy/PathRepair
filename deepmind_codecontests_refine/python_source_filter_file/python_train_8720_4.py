from collections import deque
def is_palindrome(S):
    d = deque(S)
    while d:
        if len(d) <= 1:
            return True
        if d[0] != d[-1]:
            return False
        d.popleft()
        d.pop()
    return True
def union(S1,S2):
    l1 = len(S1)
    l2 = len(S2)
    for i in range(min(l1,l2)):
        if S1[i] != S2[-i-1]:
            return (-1,'')
    if abs(l1-l2) <= 1:
        return (2,'')
    if l1 > l2:
        return (0,S1[l2:])
    else:
        return (1,S2[:l1])

N = int(input())
S = []
C = []
d = deque()
dic = {}
ans = 10**18
for i in range(N):
    Si,Ci = input().split()
    Ci = int(Ci)
    S.append(Si)
    C.append(Ci)
    if is_palindrome(Si):
        ans = min(ans,Ci)
    else:
        d.append((Ci,Si,0))
        d.append((Ci,Si,1))
        dic[(Si,0)] = Ci
        dic[(Si,1)] = Ci
while d:
    cost,string,order = d.popleft()
    for i in range(N):
        if order == 0:
            x,y = union(string,S[i])
        else:
            x,y = union(S[i],string)
        if x == -1:
            continue
        if is_palindrome(y):
            ans = min(ans,cost+C[i])
        else:
            if (y,x) in dic.keys():
                if dic[(y,x)] > cost+C[i]:
                    d.append((cost+C[i],y,x))
                    dic[(y,x)] = cost+C[i]
            else:
                d.append((cost+C[i],y,x))
                dic[(y,x)] = cost+C[i]
if ans == 10**18:
    print(-1)
else:
    print(ans)
