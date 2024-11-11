n = int(input())
s = [input() for i in range(n)]
m = int(input())
t = [input() for i in range(m)]

print(max([s.count(text)-t.count(text) for text in set(s) | set(t)]))