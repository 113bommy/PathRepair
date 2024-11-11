#B.Simple Molecules
a,b,c = map(int,input().split())
if a<(b+c) and b<(a+c) and c<(a+b) and (a+b+c)%2==0:
    print((a+b-c)//2,(b+c-a)//2,(c+a-b)//2)
else:
    print("Impossible")