n = int(input())
w = list(map(int, input().split()))
l = []

for i in range(1, n):
  l.append(abs(sum(w[i:]) - sum(w[:t])))
  
print(min(l))