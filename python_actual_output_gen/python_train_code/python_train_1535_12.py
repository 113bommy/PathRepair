a=input()
if len(a)==2:
    print(0)
else:
    b=a[1:-1].split(',')
    a=set(b)
    print(len(a))
