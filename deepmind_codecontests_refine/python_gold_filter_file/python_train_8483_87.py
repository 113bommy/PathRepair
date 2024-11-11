[a,b] = map(int, input().split())
if a<=b:
    print(a, (b-a)//2)
else:
    print(b, (a-b)//2)