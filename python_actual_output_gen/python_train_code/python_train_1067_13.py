n = int(input())
x1, x2 = map(int, input().split())
l = []
for i in range(n):
    ki, bi = map(int, input().split())
    l.append([x1*ki+bi, x2*ki+bi])
l.sort(key = lambda x:x[0])
for i in range(len(l)-1):
    if l[i][1] > l[i+1][1]: print('YES'); exit()
print('NO')