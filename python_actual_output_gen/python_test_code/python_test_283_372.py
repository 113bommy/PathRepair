x,a,b=map(int, input().split())
y=b-a
print("delicious" if y<0 else "safe" if x>y else "dangerous")