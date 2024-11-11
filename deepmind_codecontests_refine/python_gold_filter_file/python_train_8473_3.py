n=int(input())
a=list(map(int, input().split()))
b={1:0,2:0,3:0,4:0,5:0,6:0,7:0}
for i in a:
    b[i]+=1
if b[1]!=n//3:
    print(-1)
elif b[2]+b[3]!=b[4]+b[6] or b[2]+b[3]!=n//3:
    print(-1)
elif b[6]<b[3] or b[2]<b[4]:
    print(-1)
else:
    for i in range(b[4]):print('1','2','4')
    for i in range(b[3]):print('1','3','6')
    for i in range(n//3-b[4]-b[3]):print('1','2','6')
                         
