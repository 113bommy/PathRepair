n = int (input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
m = 0
for i in a:
  m = m + i
l = max(b)
k = 0
for i in b:
    if k < i and i !=l:
        k = i
if m >k+l:
    print('No')
else:
    print('Yes')
