a,b = [int(x) for x in input().split()]
if a==b:
    print (a,0)
elif a>b:
    print (b,(a-b)%2)
else:
    print (a,(b-a)%2)