a, b = map(int, input().split())
for i in range(max(a, b)):
    a -= 1
    b += 1
    if a * b == 0:
        break
if i % 2 == 0:
    print("Akshat")
else:
    print("Malvika")