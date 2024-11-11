for i in range (int(input())):
    b,p,f=map(int,input().split())
    h,c=map(int,input().split())
    cout=0
    if h>c:
        while b>=2:
            if p>=1:
                cout=h+cout
                p=p-1
            elif f>=1:
                cout=c+cout
                f=f-1
            b=b-2
    elif h<c:
        while b>=2:
            if f>=1:
                cout=c+cout
                f=f-1
            elif p>=1:
                cout=h+cout
                p=p-1
            b=b-2
    else:
        cout=h*min(b//2,p+f)
    print(cout)