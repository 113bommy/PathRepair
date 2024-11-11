n = int(input())
a = [int(i) for i in input().split()]
a.sort()
k = n // 2
s, t = sum(a[:k]), sum(a[k:])
print(s *s + t * t)

