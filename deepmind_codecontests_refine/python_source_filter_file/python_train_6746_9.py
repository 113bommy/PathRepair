import bisect
N=int(input())
A=[int(input()) for _ in range(N)]
color=[]
A=A[::-1]
for a in A:
    i=bisect.bisect_left(color,a)
    if i==len(color):
        color.append(a)
    else:
        color[i]=a
print(len(color))