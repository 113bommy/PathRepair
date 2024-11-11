names=['A','B','C','D','E','F','G','H','I','J','K','L',
       'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
       'Aa','Ab','Ac','Ad','Ae','Af','Ag','Ah','Ai','Aj',
       'Ak','Al','Am','An','Ao','Ap','Aq','Ar',
       'As','At','Au','Av','Aw','Ax']
i=0
n,k=list(map(int,input().split()))
arr=input().split()
ans=[]
if arr[0]=='NO':
    ans=names[:k-1]+[names[0]]
    
    i=k
else:
    ans=names[:k]
    i=k

arr=arr[1:]
k=0
for truth in arr:
    k+=1
    if truth=="YES":
        ans+=[names[i]]
        i+=1
    else:
        ans+=[ans[k]]
print(' '.join(ans))
    
