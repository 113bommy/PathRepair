for _ in range(int(input())):
    n,k=map(int,input().split())
    s=list(input())
    l=["?"]*n
    f=0
    for i in range(n-k):
        if s[i]=="1":
            if l[i+k]=="0":
                f=1
                break
            else:
                l[i+k]="1"
        elif s[i]=="0":
            if l[i+k]=="1":
                f=1
                break
            else:
                l[i+k]="0"
    if f:
        print("NO")
    else:
        if abs(l.count("1")-l.count("0"))>l.count("?"):
            print("NO")
        else:
            print("YES")
            
        