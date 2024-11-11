n = int(input())
pos = neg = 0
for i in range(n):
    x,y = list(map(int,input().split()))
    if x<0:
        neg += 1
    else:
        pos += 1
if neg == 1 or neg == 0:
    print('YES')
elif pos == 1 and pos == 0:
    print('YES')
else:
    print('NO')