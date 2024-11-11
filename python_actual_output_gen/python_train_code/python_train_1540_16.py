n,c=[int(i) for i in input().split()]
p=list(map(int,input().split()))
t=list(map(int,input().split()))
l,r,t1=0,0,0
for i in range(n):
    t1+=t[i]
    l+=max(0,p[i]-c*t1)
t1=0
for i in range(n-1,-1,-1):
    t1+=t[i]
    r+=max(0,p[i]-c*t1)
if l>r:
    print("Limark")
elif l<r:
    print("Radewoosh")
else :
    print("Tie")
