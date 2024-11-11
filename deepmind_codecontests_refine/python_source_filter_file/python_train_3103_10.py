n = int(input())
w = [int(i) for i in input().split()]
s = []
for i in range(1,n):
  s.append(abs(sum(w[:i])-sum(w[i:]))
print(min(s))