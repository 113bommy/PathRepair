t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    a = s.count("P")
    b = s.count("R")
    c = s.count("S")
    if a >= c and b >= c:
        print("P" * n)
    elif b >= a and c >= a:
        print("R" * n)
    else:
        print("S" * n)