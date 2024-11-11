n,q=map(int,input().split())
s=input()+" "
A=[0]*(n+1)
cnt=0
for i in range(1,n):
    if s[i-1]+s[i]=="AC":
        cnt +=1
    A[i+1]=cnt

for i in range(q):
    l,r=map(int,input().split())
    print(A[r]-A[l])