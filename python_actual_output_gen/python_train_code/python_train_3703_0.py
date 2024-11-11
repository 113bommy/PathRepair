n=int(input())
a=0
y=0
for i in range(n):
    x,y=[int(i) for i in input().split()]
    if x<0:
        a+=1
    else:
        y+=1
if a<2 or y<2:
    print('YES')
else:
    print('NO')
