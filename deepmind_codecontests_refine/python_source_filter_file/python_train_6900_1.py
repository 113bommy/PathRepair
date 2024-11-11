# http://codeforces.com/problemset/problem/143/B
def pr(a,b):
    i=0
    ans.append('$')
    n=len(a)
    while i<n:
        
        if (n-i)%3==0:
            ans.append(',')
        ans.append(a[i])
        i+=1
    ans.append('.')
    ans.append(b[:2] if len(b)!=1 else b[0]+'0')



p=(input().split('.'))
if len(p)==1:
    p.append('00')
dec,frac=p
ans=[]
if p[0][0]=='-':
    ans.append('(')
    pr(dec[1:],frac)
    ans.append(')')
else:
    pr(dec,frac) 


print(''.join(ans))
    
