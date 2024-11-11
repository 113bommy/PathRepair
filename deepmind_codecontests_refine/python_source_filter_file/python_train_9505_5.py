import sys

input = lambda :sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n,m = map(int,input().split())
    s = [input() for i in range(n)]

    same = False
    u,t = -1,-1
    for i in range(n):
        for j in range(i+1,n):
            if s[i][j]==s[j][i]:
                u,t = i,j
                same = True

    if same:
        print("YES")
        ans = [0 for i in range(m+1)]
        for i in range(m+1):
            if i%2==0:
                ans[i] = u + 1
            else:
                ans[i] = t + 1
        print(*ans)
        continue
    elif m%2==1:
        print("YES")
        ans = [0 for i in range(m+1)]
        for i in range(m+1):
            if i%2==0:
                ans[i] = 1
            else:
                ans[i] = 2
        print(*ans)
        continue

    A = [-1 for i in range(n)]
    B = [-1 for i in range(n)]
    for i in range(n):
        for j in range(n):
            if s[i][j]=="a":
                A[i] = j
            elif s[i][j]=="b":
                B[i] = j

    u,t,mid = -1,-1,-1
    for i in range(n):
        for j in range(n):
            if s[i][j]=="a" and A[j]!=-1:
                u,t,mid = i,A[j],j
            elif s[i][j]=="b" and B[j]!=-1:
                u,t,mid = i,B[j],j

    if u!=-1:
        print("YES",u,t,mid)
        k = m//2
        if (k-1)%2==1:
            L = k//2
            ans = [mid+1,u+1] * L + [mid+1] + [t+1,mid+1] * L
        else:
            L = k//2
            ans = [u+1,mid+1] * L + [u+1,mid+1,t+1] + [mid+1,t+1] * L
        print(*ans)
        assert len(ans)==m+1
        continue
    else:
        print("NO")
