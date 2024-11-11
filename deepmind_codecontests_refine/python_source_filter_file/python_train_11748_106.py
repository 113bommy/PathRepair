x,a,b=map(nt,input().split())
print("delicious" if a-b>=0 else "safe" if b-a<=x else "dangerous")