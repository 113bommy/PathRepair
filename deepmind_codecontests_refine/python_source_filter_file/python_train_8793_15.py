
def solve(n,m):
    if n >= m:
        return n-m
    else:
        if m%2==0:
            if m/2<n:
                return n-(m//2)+1
            elif m/2>n:
                return 1+solve(n,m/2)
            else:
                return 1
        else:
            return 1+solve(n,m+1)
        

a, b = map(int, input().split())
print(solve(a,b))