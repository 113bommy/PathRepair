n,k=map(int,input().split())
s=input()
s1=sorted(set(s))
if k>n:
    print(s+s1[0]*(k-n))
else:
    i=k-1
    while s[i]>=s1[-1] and i>-1:
        i-=1
    d=s1.index(s[i])
    print(s[:i]+s1[d+1]+s1[0]*(k-i-1))