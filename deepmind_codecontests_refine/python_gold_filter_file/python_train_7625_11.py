t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    a = s.count("P")
    b = s.count("R")
    c = s.count("S")
    if b >= c and b >= a:
        print("P" * n)
    elif a >= b and a >= c:
        print("S" * n)
    else:
        print("R" * n)