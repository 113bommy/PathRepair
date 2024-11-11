n,k = map(int,input().split())
def doit(n,l,k):
    k -= l
    t = []
    for i in range(1,n+1):
        s = []
        for j in range(1,n+1):
            if i == j:
                if i <= l:
                    s.append('1')
                else:
                    s.append('0')
            elif i > j:
                s.append(t[j-1][i-1])
            else:
                if k > 0:
                    s.append('1')
                    k -= 2
                else:
                    s.append('0')
        t.append(s)
    for i in t:
        print(' '.join(i))
if k > n**2:
    print(-1)
else:
    if k % 2 == 0:
        for i in range(0,n,2):
            if k <= i*(2*n-i):
                doit(n,i,k)
                break
    else:
        for i in range(1,n+1,2):
            if k <= i*(2*n-i):
                doit(n,i,k)
                break