T = int(input())
for i in range(T):
    N,A,B,C,D = map(int,input().split())
    memo = {0:0,1:D}
    def f(n):
        if n in memo:
            return memo[n]
        else:
            res = D*n
            r2 = n%2
            r3 = n%3
            r5 = n%5
            res = min(res,f(n//2)+A+r2*D,f(n//3)+B+r3*D,f(n//5)+C+r5*D)
            res = min(res,f((n+1)//2)+A+(2-r2)*D,f((n+2)//3+1)+B+(3-r3)*D,f((n+4)//5+1)+C+(5-r5)*D)
            memo[n] = res
            return res
    print(f(N))