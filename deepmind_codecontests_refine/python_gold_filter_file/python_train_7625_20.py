##RRRRRR===PPPPPP
##RPRPRPRP=PSPSPSPS
##
t=int(input())
for _ in range(t):
    s=str(input())
    n=len(s)
    a={'R','P','S'}
    r=s.count('R')
    p=s.count('P')
    s=s.count('S')
    if r==max(r,p,s):
        ans=n*'P'
    elif p==max(r,p,s):
        ans=n*'S'
    else:
        ans=n*'R'
    print(ans)
            
        
    
