t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    s=input()
    b=[]
    for i in range(n)[::-1]:
        for e in b:
            a[i]=min(a[i],a[i]^e)
        if a[i]:
            if s[i]=="0":
                b+=a[i]
            else:
                print(1)
                break
    else:
        print(0)