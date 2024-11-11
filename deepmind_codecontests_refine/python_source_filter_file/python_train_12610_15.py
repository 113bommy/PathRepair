def ia():
    n=input().split()
    return list(map(int,n))
def ic():
    return list(input())
def ii():
    return int(input())

n=int(ii())
k=int(n/3)
s=ic()

from collections import Counter

d=Counter(s)
a=d['0']
b=d['1']
c=d['2']

if(a==k and b==k and c==k):
    print(''.join(s))
else:
    if(c<k):
        if(b>k):
            for i in range(n-1,0,-1):
                if(s[i]=='1'):
                    s[i]='2'
                    c+=1
                    b-=1
                if(b==k):
                    break
                if(c==k):
                    break
        if(a>k):
            for i in range(n-1,0,-1):
                if(s[i]=='0'):
                    s[i]='2'
                    c+=1
                    a-=1
                if(c==k):
                    break
                if(a==k):
                    break
    if(a<k):
        if(c>k):
            for i in range(n):
                if(s[i]=='2'):
                    s[i]='0'
                    a+=1
                    c-=1
                if(c==k):
                    break
                if(a==k):
                    break
        if(b>k):
            for i in range(n):
                if(s[i]=='1'):
                    s[i]='0'
                    a+=1
                    b-=1
                if(b==k):
                    break
                if(a==k):
                    break
    
    if(b<k):
        if(c>k):
            for i in range(n):
                if(s[i]=='2'):
                    s[i]='1'
                    b+=1
                    c-=1
                if(b==k):
                    break
                if(c==k):
                    break
        if(a>k):
            for i in range(n-1,0,-1):
                if(s[i]=='0'):
                    s[i]='1'
                    b+=1
                    a-=1
                if(b==k):
                    break
                if(a==k):
                    break

print(''.join(s))