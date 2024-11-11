from collections import Counter as C
n = int(input())
c = C(map(int, input().split()))
m = c[min(c.keys())]
print("Alice" if m < n / 2 else "Bob")