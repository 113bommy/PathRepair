a,b=map(int,input().split())
print(int(b if a>=13 else b/2 if a>=6 else 0))