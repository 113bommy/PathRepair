H,W=map(int,input().split())
s=[list(input()) for _ in range(H)]
D={}

for h in range(H):
    for w in range(W):
        if s[h][w] in D:
            D[s[h][w]]+=1
        else:
            D[s[h][w]]=1

odd=0
semi=0
for d in D:
    if D[d]%4==1:
        odd+=1
    elif D[d]%4==2:
        semi+=1
    elif D[d]%4==3:
        odd+=1
        semi+=1

if H%2==0 and W%2==0:
    if odd==semi==0:
        print("Yes")
    else:
        print("No")
elif H%2==1 and W%2==1:
    if odd==1 and semi<=H+W-2:
        print("Yes")
    else:
        print("No")
else:
    if H%2==1:
        if odd>0 or semi>W-1:
            print("No")
        else:
            print("Yes")
    else:
        if odd>0 or semi>H-1:
            print("No")
        else:
            print("Yes")