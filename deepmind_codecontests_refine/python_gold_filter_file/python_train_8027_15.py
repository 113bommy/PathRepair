n,k=map(int,input().split())
a=[int(z)for z in input().split()]+[0]
cnt=0;x=0;s=sum(a)/k;A=[]
for i in range(1+n):
    if cnt<s:
        cnt+=a[i];x=x+1
    elif cnt==s:
        A.append(x);cnt=a[i];x=1
    else:
        x=-1;A.clear();break
print('YNeos'[x<0::2])
if len(A): print(*A,sep=' ')