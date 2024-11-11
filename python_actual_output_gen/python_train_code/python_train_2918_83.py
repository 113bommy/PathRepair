a,b = map(int, input().split())
if a>=b:
    print(b, (a-b)//2)
else:
    print(a, (a-b)//2)
