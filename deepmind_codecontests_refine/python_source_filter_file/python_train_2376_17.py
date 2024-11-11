#109_D
H,W=map(int,input().split())
A=[]
Ans=[]
for i in range(N):
    a=list(map(int,input().split()))
    if i%2==0:
        A+=a
    else:
        A+=a[::-1]
for i in range(H*W-1):
    if A[i]%2==1:
        A[i]-=1
        A[i+1]+=1
        y1=i//W+1
        x1=i%W+1 if y1%2==1 else W-i%W
        y2=(i+1)//W+1
        x2=(i+1)%W+1 if y2%2==1 else W-(i+1)%W
        Ans.append([y1,x1,y2,x2])
print(len(Ans))
for ans in Ans:
    print(*ans)