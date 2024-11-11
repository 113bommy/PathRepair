import math
n=int(input())
a=list(map(int, input().split(' ')))

def mat(a,b,x,y):
    i=a
    j=b
    return (i*y)+(j+1)

def valid(mat,curr,next,x,y):
    # (i + 1, j) — only if i < x;
    # (i, j + 1) — only if j < y;
    # (i - 1, j) — only if i > 1;
    # (i, j - 1) — only if j > 1.

    i=(curr-1)//y
    j=(curr-1)%y

    # x=x-1
    # y=y-1
    # print('curr next i j x y', curr,next,i,j,x,y)
    if (i<x-1 and mat(i+1,j,x,y)==next):
        return True
    if (j<y-1 and mat(i,j+1,x,y)==next):
        return True
    if (i>0 and mat(i-1,j,x,y)==next):
        return True
    if (j>0 and mat(i,j-1,x,y)==next):
        return True
    return False

max_diff=0
for i in range(n-1):
    if abs(a[i]-a[i+1]) > max_diff:
        max_diff=abs(a[i]-a[i+1])
y=max_diff
if y!=0:
    x=math.ceil(max(a)/y)
# print(x,y)
if max_diff==0:
    flag=False

elif x>1000000000 or y>1000000000 or max_diff==0:
    flag=False
else:
    # mat = [[0 for i in range(y)] for j in range(x)]
    # # print(mat)
    #
    # for i in range(x):
    #     for j in range(y):
    #         mat[i][j]=(i*y)+(j+1)
    # # print(mat)
    flag=True
    for c in range(n-1):
        curr=a[c]
        next=a[c+1]
        # print(mat,curr,next,x,y)
        # print(valid(mat,curr,next,x,y))
        if curr==next or valid(mat,curr,next,x,y)==False:
            # print('curr',curr)
            flag=False
            break

if n==1:
    x=1
    y=1
    flag=True
if flag==False:
    print('NO')
else:
    print('YES')
    print(x,y)
