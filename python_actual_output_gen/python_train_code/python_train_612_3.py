s=input()
n=len(s)
sa=[-1]*n
f=[0]*(n+1)
ex=[-1]*n
arr=[]
for i in range(n):
    if s[i]=='(':
        arr.append(i)
    else:
        if len(arr)!=0:
            p=arr.pop()
            sa[i]=p
            ex[i]=p
            if s[p-1]==')' and sa[p-1]!=-1:
                ex[i]=sa[p-1]
            d=i-ex[i]+1
            f[d]+=1
flag=False
for i in range(len(f)-1,0,-1):
    if f[i]!=0:
        print(i,f[i])
        flag=True
        break
if flag==False:
    print(0,1)
 