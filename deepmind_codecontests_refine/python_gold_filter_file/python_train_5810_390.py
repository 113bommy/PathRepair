a,b=map(int,input().split())
print("IMPOSSIBLE" if abs(a-b)%2==1 else (a+b)//2)