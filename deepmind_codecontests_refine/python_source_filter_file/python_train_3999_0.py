n = int(input())
m = [input() for _ in range(n)]
print(1 if len(m) == 1 else sum(1 if m[i] == m[i+1] else 0 for i in range(len(m)-1)))