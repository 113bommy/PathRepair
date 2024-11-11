t=int(input())
for o in range(t):
    n=input()
    if len(n)%2!=0:
        print("NO")
    else:
        d=len(n)//2
        b=n[0:d]
        c=n[d:]
        print(b,c)
        if b==c:
            print("YES")
        else:
            print("NO")