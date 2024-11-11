t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int,input().split()))
    b = a[::-1]
    d = dict()
    for i in range(len(a)):
        d[a[i]*b[i]] = 1
    print("YNEOS"[not len(d)==1 and a[::2]==a[1::2]::2])