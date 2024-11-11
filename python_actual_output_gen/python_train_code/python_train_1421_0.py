a,b,c,d=map(int,input().split())
a1=0.3*a
a2=a-(a/250)*c
aa=max(a1,a2)
b1=0.3*b
b2=b-(b/250)*d
bb=max(b1,b2)
if aa>bb:
    print("Vasya")
elif aa==bb:
    print("Tie")
elif aa<bb:
    print("Misha")
