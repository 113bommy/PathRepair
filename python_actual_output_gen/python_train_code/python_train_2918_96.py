a, b = map(int, input().split())
if(a>b):
    print(b,(a-b)//2)
elif(a<b):
    print(a,(b-a)//2)
else:
    print(a)