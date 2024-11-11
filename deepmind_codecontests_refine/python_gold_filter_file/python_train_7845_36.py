
cases=eval(input())
for _ in range(cases):
    angle=eval(input())
    for side in range(3, 1000):
        guess=float(180*(side-2))/side
        if guess==angle:
            print("YES")
            break
        if guess>angle:
            print("NO")
            break