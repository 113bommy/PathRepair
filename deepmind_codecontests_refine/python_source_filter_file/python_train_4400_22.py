n = int(input())
a = [int(x) for x in input().split()]
b = [0]*n
for i in range(n):
 a[i] = a[i]-1
for m in range(n):
    for i in range(n):
      if a[i] == m:
       b[m] = i
       continue
      else:
          continue
for i in range(n):
    b[i] = b[i]+1
print(b)
