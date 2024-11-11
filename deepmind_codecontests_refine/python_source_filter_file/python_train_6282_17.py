from fractions import Fraction
n,m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if n>m:
    if a[0]*b[0]>=0:
        print("Infinity")
    else:
        print("-Infinity")
elif m>n:
    print("0/1")
else:
    ans=str(Fraction(a[0],b[0]))
    if len(ans)==1:
        print(ans+"/1")
    else:
        print(ans)