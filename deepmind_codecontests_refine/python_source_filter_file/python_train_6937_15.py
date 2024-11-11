n, pos, l, r=list(map(int, input().split()))
if r-l+1==n:
    print(0)
elif l==1:
    print(max(pos-r, r-pos)+1)
elif r==n:
    print(max(pos-l, l-pos)+1)
else:
    a=max(pos-l, l-pos)
    b=max(pos-r, r-pos)
    if a>b:
        print(b+3+r-l)
    else:
        print(a+3+r-l)