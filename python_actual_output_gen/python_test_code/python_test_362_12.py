n = int(input())
k = int(input())
x = map(int, input().split())
s = 0
for xx in x:
  s += min(xx, k-xx)
print(s)