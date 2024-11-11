def solve():
    N = int(input())
    A = list(map(int,input().split()))
    mA = max(A)
    sA = set(a%3 for a in A)
    sA2 = set(A)
    if len(sA)==1:
        if mA%3==0:
            print(mA//3)
        else:
            print(mA//3+1)
    elif len(sA)==2:
        if 0 in sA and 1 in sA:
            print(mA//3+1)
        elif 0 in sA and 2 in sA:
            print(mA//3+1)
        else:
            # !
            if mA%3==1:
                if not mA-3 in sA2:
                    print(mA//3+1)
                else:
                    print(mA//3+2)
            if mA%3==2:
                print(mA//3+2)
    else:
        if mA%3==0:
            print(mA//3+1)
        elif mA%3==1:
            if not mA-3 in sA2 and not mA-1 in sA2:
                print(mA//3+1)
            else:
                print(mA//3+2)
        else:
            print(mA//3+2)

T = int(input())

for i in range(T):
    solve()