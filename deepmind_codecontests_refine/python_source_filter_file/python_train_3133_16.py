s1=str(input())
s2=str(input()) 
if s1==s2:
    print(0)
else:
    r1=len(s1)-1; r2=len(s2)-1
    n=r1+r2+2
    while r1>0 and r2>0:
        if s1[r1]!=s2[r2]:
            break 
        r1-=1; r2-=1 
        n-=2
    print(n)
 
        


