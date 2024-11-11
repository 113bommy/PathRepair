s=input()
s=list(s)
n=len(s)
q=int(input())
def rotate(s,l,r,k):
    s1=s[:l]+list(s[r-k:r])+s[l:l+(r-l+1-k)]+s[r+1:]
    return s1 
for i in range(q):
    l,r,k=map(int,input().split())
    l-=1 
    r-=1
    k=k%(r-l+1)
    s=rotate(s,l,r,k)
print(*s,sep='')