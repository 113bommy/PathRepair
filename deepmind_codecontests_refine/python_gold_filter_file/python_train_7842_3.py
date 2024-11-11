#https://codeforces.com/problemset/problem/198/A
k,b,n,t = map(int, input().split())
x = 1
a = 0
flag = False
for _ in range(n):
    z = k*x + b
    x = z
    a += 1
    if z > t:
        flag = True
        break
if flag:
    print(n-a+1)
else:
    print(n-a)

