N,X=list(map(int,input().split()))
L=list(map(int,input().split()))
cnt=1
d=0
for i in L:
    d+=L[i]
    if d<=X:
        cnt+=1

print(cnt)