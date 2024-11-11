n, k = map(int, input().split())
e=0
while pow(k, e) < n:
  e+=1
print(e)