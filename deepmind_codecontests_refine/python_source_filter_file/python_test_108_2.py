from sys import stdin
from bisect import bisect_left
input=stdin.readline
rn=lambda:int(input())
rns=lambda:map(int,input().split())
rl=lambda:list(map(int,input().split()))
rs=lambda:input().strip()
YN=lambda x:print('YES') if x else print('NO')
ceil_div=lambda a,b:-(-a//b)
mod=10**9+7

for _ in range(rn()):
    n=rn()
    a=rl()
    b=rl()
    a_index = {a[i]:i for i in range(n)}
    b_index = {b[i]:i for i in range(n)}
    a_sort = sorted(a)
    b_sort = sorted(b)
    ans = [0 for i in range(n)]
    switch=1
    curr=[a_index[a_sort[-1]]]
    ans[curr[0]]=1
    while len(curr)>0:
        new=[]
        for index in curr:
            if switch==1:
                while len(b_sort)>0 and b_sort[-1]>index:
                    new.append(b_index[b_sort.pop()])
            else:
                while len(a_sort)>0 and a_sort[-1]>index:
                    new.append(a_index[a_sort.pop()])
        switch = 0 if switch else 1
        for index in new:
            ans[index]=1
        curr=new
    print(''.join(map(str,ans)))
