n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]

print(max(s.count(S) - t.count(S) for S in s) + [0])