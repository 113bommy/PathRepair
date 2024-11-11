n,a,b=map(int,input().split())

mR = n - b + 1
mL = n - a
print(min(b + 1,mL))