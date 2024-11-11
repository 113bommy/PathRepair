p=[int(i) for i in input().split()]
q=sum(p)/2
output=False
for x1 in range(4):
    for x2 in range(x1+1,5):
        for x3 in range(x2+1,6):
            if p[x1]+p[x2]+p[x3]==q:
                output=True
                break
if output==False:
    print('NO')
else:
    print('YES')
