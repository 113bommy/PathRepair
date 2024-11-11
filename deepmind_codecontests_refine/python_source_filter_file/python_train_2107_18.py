# The expert at anything was once a beginner. Helen Hayes
# by : Blue Edge - Create some chaos
for _ in range(int(input())):
    n=int(input())
    t=list(map(int,input().split()))
    k=len(set(t))
    if k==1:
        print(1)
        print("1 "*n)
        continue

    if n&1:
        if t[0]==t[-1]:
            print(2)
            print("1 2 "*(n//2)+"1")
        elif t[-1]==t[-2]:
            print(2)
            print("1 2 "*(n//2)+"2")
        else:
            p="1 2 "*(n//2)
            res=True
            for i in range(1,n):
                if t[i]==t[i-1]:
                    if i&1:
                        p=p[:2*i]+"1 "+p[2*i:]
                    else:
                        p=p[:2*i]+"2 "+p[2*i:]
                    res=True
                    break
            if not res:
                print(2)
                print(p)
            else:
                print(3)
                print(p+"3")

    else:
        print(2)
        print("1 2 "*(n//2))
