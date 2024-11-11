n = int(input())
t = int(input())
flag = 1
for case in range(n):
    a,b=map(int,input().split())
    if a==t or t==7-a or b==t or t==7-b:
        flag=0

if flag==1:
    print('YES')
else:
    print('NO')
