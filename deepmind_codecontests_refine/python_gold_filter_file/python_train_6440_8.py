p = 0
f = 0
n, a, b = map(int, input().split())
for i in input():
    if i == "a" and p < a+b:
        p += 1
        print("Yes")
    elif i == "b" and p < a+b and f < b:
        p += 1
        f += 1
        print("Yes")
    else:
        print("No")