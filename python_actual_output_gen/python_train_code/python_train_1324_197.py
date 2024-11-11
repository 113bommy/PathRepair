a,b,c = map(int,input().split())

if c < a+b:
    print(b+c)
else:
    print(b+(b+a))