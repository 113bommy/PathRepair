n,m = map(int,input().split())
a = []
b = []

for _ in range(n):
    a += [list(input())]
for _ in range(m):
    b += [list(input())]

for i in range(n-1):
    for j in range(n-1):
        if [k[j:m+j] for k in a[i:m+i]] == b:
            print('Yes')
            exit()
print('No')
