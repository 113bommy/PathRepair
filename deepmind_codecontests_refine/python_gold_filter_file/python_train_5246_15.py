n=int(input())
s=input()
if s.count('R')==0:
    print(s.index('L')+1,s.index('L'))
elif s.count('L')==0:
    idx=s.index('R')
    while s[idx]=='R':
        idx+=1
    print(idx,idx+1)
else :
    idx=s.index('R')
    while s[idx]=='R':
        idx+=1
    print(idx+1,idx+1)
    