n, k = input().strip().split(' ')
n, k = [int(n), int(k)]
p = list(map(int, input().strip().split(' ')))
d=0
x=0
for i in range(n):
     d=86400-p[i]
     x=x+d
     if x==k:
          print(i+1)
          break
     
