n = int(input())
a = []
s1 = s2 = 0

for i in range(n):
    a.append([int(i) for i in input().split()])
    s1 += a[i][0]
    s2 += a[i][1]

if s1 % 2 == 0 and s2 % 2 == 0:
    print(0)
if s1 % 2 != s2 % 2:
    print(-1)
else:
    for i in a:
        if i[0] % 2 != i[1] % 2:
            print(1)
            exit(0)
    
    print(-1)