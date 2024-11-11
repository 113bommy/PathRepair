n = int(input())
A1 = []
A2 = []
A3 = []
A4 = []
l1,r1 = 1000000000,0
l2,r2 = 1000000000,0
for i in range(n):
    a,b = map(int,input().split())
    if b < l1 :
        l1 = b
        A1 = [a,b]
    if a > r1:
        r1 = a
        A2 = [a,b]
m = int(input())
for i in range(m):
    a,b = map(int,input().split())
    if b < l2 :
        l2 = b
        A3 = [a,b]
    if a > r2:
        r1 = a
        A4 = [a,b]
x,y = -1,-1
if A1 != [] and A4 != []:
    x = A4[0] - A1[1]
if A2 != [] and A3 != []:
    y = A2[0] - A3[1]
if x > 0 and x > y:
    print(x)
elif y > 0 and y > x:
    print(y)
else:
    print(0)    