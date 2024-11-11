a,b=map(int, input().split())

if a==b:
    print("Draw")
elif a==1 or (b!=1 and a>b):
    print("Alice")
else:
    print("Bob")
