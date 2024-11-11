a=list(input())
b=int(input())


t=len(set(a))
if b>26:
    print('impossible')
else:
    if t==b:
        print(0)
    elif t<b and len(a)-t>= b-t:
        print(b-t)
    elif t>b:
        print(t-b)
    else:
        print('impossible')
