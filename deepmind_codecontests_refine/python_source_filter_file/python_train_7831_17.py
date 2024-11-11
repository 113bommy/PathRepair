t=int(input())
for tc in range(t):
    s=input()
    co=s.count('0')
    le=len(s)
    if co==le:
        print(s)
    else:
        ca=le*2-1
        if s[0]=="0":
            for i in range(ca):
                if i%2==0:
                    print(0,end="")
                else:
                    print(1,end="")
            print()
        else:
            for i in range(ca):
                if i%2==0:
                    print(1,end="")
                else:
                    print(0,end="")
            print()