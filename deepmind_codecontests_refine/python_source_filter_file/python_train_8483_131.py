a,b=map(int,input().split())
if a < b:
    print(a,(b-a)//2)
elif b > a:
    print(b,(a-b)//2)
else:
    print(a,"0")