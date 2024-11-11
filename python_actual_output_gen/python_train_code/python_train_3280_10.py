a=int(input()) 
l=list(map(int,input().split())) 
ans=l[0]
idx=0 
flag=0 
for i in range(1,a):
    if l[i]<ans:
        ans=l[i]
        idx=i+1
        flag=0 
    elif l[i]==ans:
        flag=1 

if flag==0:
    print(idx)
else:
    print("Still Rozdil")
