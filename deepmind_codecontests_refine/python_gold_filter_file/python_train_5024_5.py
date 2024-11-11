for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    s=a[0]
    for i in range(1,n):
        s^=a[i]
    if s==0:
        print("DRAW")
    else:
        xx=1<<29
        an=0

        for i in range(30):
            c=0
            for j in range(n):
                if a[j]&xx:
                    c+=1
            if c%2==1:
                if c%4==1:
                    an=1
                elif n%2==0:
                    an=1
                else:
                    an=0
                break
            xx=xx//2
        if an==1:
            print('WIN')
        else:
            print('LOSE')