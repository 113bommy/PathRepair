a,b,c,d=map(int,input().split())
print("Left"if a+b>c+d else "RIght" if a+b<c+d else "Balanced")