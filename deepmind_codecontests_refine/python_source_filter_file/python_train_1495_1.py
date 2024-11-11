l,r=map(int,input().split())
'''
cnt = 0 
for i in range(l,r+1):
    if str(i)[0]==str(i)[-1]: cnt+=1 
print(cnt)
def upto_x(n):
    if n<=1000:
        cnt = 0 
        for i in range(1,n+1):
            if str(i)[0]==str(i)[-1]: cnt+=1 
        return cnt 
    s=str(n)
    sm=0 
    slen=len(s)
    if slen>=1:
        sm=0 
    elif slen>=2:
        sm+=9 
    elif slen>=3:
        sm+=10 
    else:
        sm=10**(slen-2) 
    print(sm)
    now=10**(slen-1) 
    now*=int(s[0])
    if s[-1]>=s[0]:
        now+=10**(slen-1)
    sm+=now 
    return sm 
print(upto_x(r))
print(upto_x(r)-upto_x(l-1))'''
def upto_x(n):
    if n<10:
        return 9 
    sm=n//10 +9 
    if str(n)[-1]<str(n)[0]:
        sm-=1 
    return sm 
print(upto_x(r)-upto_x(l-1))