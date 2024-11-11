a,b,c=map(int, input().split())
if a%2 and b%2 and c%2:
    print(0)
else:
    print(min(a*b,b*c,c*a))