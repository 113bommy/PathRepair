n, m, k = map(int, input().split())
s = (n + m) // k
o1, o2 = n % k, m % k
print(s, min(o1, o2) if o1 + o2 >= k else 0)
