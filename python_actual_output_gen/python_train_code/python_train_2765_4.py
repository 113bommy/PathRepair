n = int(input())
t = int(input())
flag = 1
for case in range(n):
    a,b=map(int,input().split())
    if a==7 or a==7-a or b==7 or b==7-b:
        flag=0

if flag:
    print('YES')
else:
    print('NO')
