a = []
n = int(input())
for i in range(n):
    a.append(list(map(int,input().split())))
k = int(input())
for i in range(n):
    if k in a[i] or k < a[i][1]: print(n-i)