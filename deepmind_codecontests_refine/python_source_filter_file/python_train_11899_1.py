t = int(input())
lazyfac = [1,1]
def upfac(lazyfac, n):
    while len(lazyfac)<n+1:
        lazyfac.append((lazyfac[-1]*len(lazyfac)))
        #inversfac.append(pow(lazyfac[-1], -1,MOD))
def fac2(n):
    if n==0:
        return 1
    else:
        return n*fac2(n-1)
def choose(n,m):
    d1 = n-m
    d2 = m
    p1 = max(d1,d2)
    p2 = min(d1,d2)
    num = 1
    for i in range(p1,n+1):
        num*=i
    return int(num/fac2(p2))
for test in range(t):
    n = int(input())
    m = 3
    k = 2
    a = [int(i) for i in input().split()]
    a.sort()
    ans = 0
    j = 0
    if m==0:
        ans =n
    else:
        for i in range(n-m+1):
            if j<n:
                while a[j]<=a[i]+k:
                    j+=1
                    if j==n:
                        break
            if j>=i+m:
                #print(i, j, j-i-1,m-1)
                #upfac(lazyfac, j-i-1)
                ans += choose(j-i-1,m-1)
                ans = ans
    print(ans)
