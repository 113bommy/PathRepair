n = int(input())
x = list(map(int,input().split(' ')))
y = list(map(int,input().split(' ')))
Levels = [*x,*y]
flag = 0
for i in range(1,n+1):
    if i in set(Levels):
        flag +=1
if flag == n:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')