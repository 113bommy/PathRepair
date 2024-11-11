a,b,c=map(int,input().split())
if (a+b+c)%2!=0:
    print('Impossible')
else:
    l=min(a,b);m=(a+b-c)//2
    if m<0 or m>l:
        print('Impossible')
    else:
        print(l,b-l,a-l)