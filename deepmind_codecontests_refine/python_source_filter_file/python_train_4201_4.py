a=str(input())
ma=10**5
pre,suf=[0]*len(a),[0]*len(a)
n=len(a)
for i in range(len(a)):
    if i==0:
        if ord(a[0])>96:
            pre[i]=1
        else:
            pre[i]=0
        continue
    if ord(a[i])>96:
        pre[i]=pre[i-1]+1
    else:
        pre[i]=pre[i-1]
for i in range(len(a)-1,-1,-1):
    if i==n-1:
        if ord(a[n-1])>96:
            suf[i]=0
        else:
            suf[i]=1
        continue
    if ord(a[i])<96:
        suf[i]=suf[i+1]+1
    else:
        suf[i]=suf[i+1]    
for i in range(len(a)-1):
    if pre[i]+suf[i+1]<ma:
        ma=pre[i]+suf[i+1]
ans=0
for hi in range(len(a)):
    if ord(a[hi])<66:
        ans+=1
ma=min(ans,ma)
ans=0
for ii in range(len(a)):
    if ord(a[ii])>96:
        ans+=1
ma=min(ans,ma)
print(ma)

