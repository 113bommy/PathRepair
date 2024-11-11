
q = int(input())
for _ in range(q):
    n = int(input())
    if n % 7 == 0:
        print(n//7 + 1)
    else:
        print(n//7)
