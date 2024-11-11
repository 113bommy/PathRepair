N,X=map(int,input().split())

a,p=[1],[1]

for i in range(N):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def solve(n,x): #n,x
    if n==0:
        if x<=0:
            return 0
        else:
            return 1
    elif x<=1+a[N-1]:
        return  solve(N-1,X-1)
    else:
        return p[N-1]+1+solve(N-1,X-2-a[N-1])

print(solve(N,X))


