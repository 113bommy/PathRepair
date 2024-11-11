r,g,b=map(int,input().split())
print("No" if (g*10+b)%4 else "Yes")