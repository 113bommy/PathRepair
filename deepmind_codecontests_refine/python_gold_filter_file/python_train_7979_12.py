n, m = map(int, input().split())
data = list(map(int, input().split()))
#print(data, n, m)
tetrix = [0 for i in range(n)]
for i in data:
  tetrix[i-1] += 1
print(min(tetrix))