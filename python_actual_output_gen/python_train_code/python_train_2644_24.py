a,m=list(map(int,input().split()))





if a%2==0:
    if m==0:
        print(1)
    elif 0<m<=a//2:
        print(m)
    elif a//2<m<a:
        print(a//2-m%(a//2))
    else:
        print(0)
else:
    if m==0:
        print(1)
    elif m<=a//2:
        print(m)
    elif m==a//2+1:
        print(a//2)
    elif a//2+1<m<a:
        print(a//2-(m%(a//2)-1))
    else:
        print(0)
