for _ in range(int(input())):
    n=int(input())
    a=input()
    f=10001
    m=0
    if '1' not in a:
        print(n)
    else:
        for i in range(n):
            if a[i]=='1':
                f=min(i,f)
                m=max(i,m)
        print(((n-f))*2 if (n-f)>m else (m)*2)                