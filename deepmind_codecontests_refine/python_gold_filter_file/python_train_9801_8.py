a = []
s = 0
n = int(input())
a = list(map(int,input().split(' ')))
a.sort(key=int,reverse = True)
m = int(input())
q = list(map(int,input().split(' ')))
for i in range(1,n):
  a[i] += a[i-1];
for i in q:
  print(a[i-2]+a[n-1]-a[i-1])
