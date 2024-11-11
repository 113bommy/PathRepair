def solve(n,a,b,r):
    b.sort()
    r.sort()
    i=0
    for i in range(len(b)):
        if b[i]<i+1:
            return 'NO'
    curr= i+1
    for i in range(len(r)):
        if r[i]>curr:
            return 'NO'
        curr+=1
    return 'YES'
for t in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    s = input()
    b=[];r=[]
    for i in range(n):
        if s[i]=='B':
            b.append(a[i])
        else:
            r.append(a[i])
    print(solve(n,a,b,r))