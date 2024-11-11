import sys
input = sys.stdin.readline

H,W,N=map(int,input().split())
B=[set() for i in range(H+1)]
for i in range(N):
    x,y=map(int,input().split())
    B[x].add(y)

NOW=1

for i in range(2,H+1):
    for j in B[i]:
        if j<=NOW:
            print(i-1)
            sys.exit()

    if not (NOW+1 in B[i]):
        NOW+=1

print(i)