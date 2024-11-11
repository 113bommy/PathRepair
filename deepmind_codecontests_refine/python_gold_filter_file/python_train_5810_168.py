a,b=map(int, input().split())
print(int((a+b)/2) if int((a+b)%2)==0 else "IMPOSSIBLE")