a,b,c,d=map(int,input().split())
print("balanced" if a+b==c+d else "left" if a+b>c+d else "right")