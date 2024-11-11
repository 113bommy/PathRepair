from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline())
    n,m,k=list(map(int,stdin.readline().split()))
    a=list(map(int,stdin.readline().split()));f=1
    for i in range(n-1):
        h1=a[i]
        h2=a[i+1]
        if h1>=h2:
            target=max(0,h2-1)
            m+=h1-target
        else:
            target=max(0,h2-1)
            if m<target-h1:
                f=0
                break
            m-=target-h1
    print('YES' if f else 'NO')
