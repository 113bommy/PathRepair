n,k=map(int,input().split())
k0=0
k1=0
s=str(n)
for i in range(len(s)-1,-1,-1):
    if s[i]=='0':
        k0+=1
    else:
        k1+=1
    if k0==k:
        print(k)
        break
if k>k0:
    print(len(s)-1)
    