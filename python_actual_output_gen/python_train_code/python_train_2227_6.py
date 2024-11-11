a,b=map(int,input().split())
a=(a+11)%13
b=(b+11)%13
if a==b:print("DRAW")
elif a>b:print("Alice")
else:print("Bob")