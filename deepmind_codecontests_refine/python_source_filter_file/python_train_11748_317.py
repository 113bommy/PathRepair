a,b,c = map(int,input().split())
print("delicious" if b=c else "safe" if c-b-1<=a else "dangerous")