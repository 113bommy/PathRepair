a,b=(int(x) for x in input().split())

print("IMPOSSIBLE" if (a+b)%2==1 else (a+b)/2)