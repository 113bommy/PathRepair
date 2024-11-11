from collections import Counter
n = int(input())
for _ in range(n):
    c = Counter(input())
    m = sum(i*c[str(i)] for i in range(10))
    k = sum(c[str(i)] for i in range(0, 10, 2)) 
    r = (m % 3 == 0) and (c['0'] > 0) and (k > 1)
    print("red" if r else "cyan")