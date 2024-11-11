a, b = map(int, input().split())
if a == b:
    print("Draw")
elif a > b and b!=1:
    print("Alice")
else:
    print("Bob")