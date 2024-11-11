n = int(input())
p = list(map(int,input().split()))
a = [1+30000*i for i in range(n)]
b = [1+30000*i for i in range(n-1,-1,-1)]
for x in p:
  a[x-1] += n
  n -= 1
print(" ".join(map(str,a)))
print(" ".join(map(str,b)))