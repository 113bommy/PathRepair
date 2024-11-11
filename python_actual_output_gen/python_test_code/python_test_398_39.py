n=int(input())
p=input().split()

for j in range(n):
    if p[j]=='1':
        print('NO')
        break
    else:
        if j==n-1:
            print('YES')
