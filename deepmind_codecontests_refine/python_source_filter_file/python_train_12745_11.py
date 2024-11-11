n,p,k=map(int,input().split())
if k-p<1:
    print("<<",end=" ")
for i in range(max(1,p-k),p):
    print(i,end=" ")
print("(",p,")",end=" ",sep="")
for i in range(p+1,1+min(p+k,n)):
    print(i,end=" ")
if n>p+k:
    print(">>")
