import sys
input = sys.stdin.readline

h,w=map(int,input().split())
MAP=[list(input()) for i in range(h)]
flag=0

for i in range(1,h-1):
    for j in range(1,w-1):
        if MAP[i][j]==MAP[i-1][j]==MAP[i+1][j]==MAP[i][j-1]==MAP[i][j+1]=="*":
            CI=i
            CJ=j
            flag=1
            break

    if flag==1:
        break

if flag==0:
    print("NO")
    sys.exit()

LIST=[[0]*w for i in range(h)]

for i in range(CI,-1,-1):
    if MAP[i][CJ]=="*":
        LIST[i][CJ]=1
    else:
        break

for i in range(CI,h):
    if MAP[i][CJ]=="*":
        LIST[i][CJ]=1
    else:
        break

for j in range(CJ,-1,-1):
    if MAP[CI][j]=="*":
        LIST[CI][j]=1
    else:
        break

for j in range(CJ,w):
    if MAP[CI][j]=="*":
        LIST[CI][j]=1
    else:
        break

#print(LIST)

for i in range(h):
    for j in range(w):
        if MAP[i][j]=="*" and LIST[i][j]==0:
            print("NO")
            sys.exit()

print("YES")
