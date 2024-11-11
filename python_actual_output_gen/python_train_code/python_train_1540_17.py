n,c=map(int,input().split())
l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
c1=0
c2=0
t=0

for i in range(n):
    t+=l2[i]
    c1+=max(0,l1[i]-(2*t))
l1.reverse()
l2.reverse()
t=0
for i in range(n):
    t+=l2[i]
    c2+=max(0,l1[i]-(2*t))
if(c1>c2):
    print('Limak')
elif(c1<c2):
    print('Radewoosh')
else:
    print('Tie')
    
    
    