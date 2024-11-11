a,b,c,d=map(int,input().split())
print(["Left" if a+b>c+d else "Right","Balanced"][a+b==c+d])
