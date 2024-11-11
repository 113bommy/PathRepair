a,b,c=map(int,input().split())
for i in range(10**9):
    if i*a%b==c:
        print('YES')
        exit()

print('NO')
