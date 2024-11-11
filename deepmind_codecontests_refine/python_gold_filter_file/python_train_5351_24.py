r, c = map(int,input().split(' '))
count = 0
A = []
x = 0

for i in range(r):
    n = list(input())

    if 'S' not in n:
        x += 1

    A.append(n)

y = []
p = 0

for i in range(c):
    for j in range(r):
        y.append(A[j][i])

    if 'S' not in y:
        p += 1

    y = []
    
count = r*c - (r-x)*(c-p)

print(count)