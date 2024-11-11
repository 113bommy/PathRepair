def dist(A,B):
    return abs(A[0]-B[0]) + abs(A[1]-B[1])


A = [int(x) for x in input().split()]

XA = (A[::2])
YA = A[1::2]

Xmin,Xmax = min(XA),max(XA)
Ymin,Ymax = min(YA),max(YA)

B = [int(x) for x in input().split()]
XB = sum(B[::2])//4
YB = sum(B[1::2])//4

can = False

for i in range(0,len(B),2):
    x = B[i]
    y = B[i+1]

    if x <= Xmax and x >= Xmin and y <= Ymax and y >= Ymin:
        can = True

if XB <= Xmax and XB >= Xmin and YB <= Ymax and YB >= Ymin:
    can = True

# for i in range(0,len(A),2):
#     if dist((XB,YB),(A[i],A[i+1])) <= dist((XB,YB),(B[0],B[1])):
#         can = True

print("YES" if can else "NO")