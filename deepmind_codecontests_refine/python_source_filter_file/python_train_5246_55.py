n=int(input())
l=input()
L=l.count('L')
R=l.count('R')
if L==0:
    s=l.index('R')+R
    t=s+1
elif R==0:
    t=l.index('L')+1
    s=t+1
else:
     s=l.index('R')+1
     t=l.index('L')
print(s,end=' ')
print(t)