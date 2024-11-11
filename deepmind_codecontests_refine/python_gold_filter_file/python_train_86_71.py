a,b,c=map(int,input().split())

print("Yes" if a==b+c or b==a+c or c== a+b else "No")