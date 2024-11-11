a,b,c,d =list(map(int,input().split()))
m=max((3*a)/250,a-(a/250)*c)
v=max((3*b)/250,b-(b/250)*d)
if m>v:
    print("Misha")
elif v>m:
    print("Vasya")
else:
    print("Tie")