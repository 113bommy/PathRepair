N=int(input())
X=list(map(int,input().split()))
c=0
d=sum(X)/N
for i in X:
   c+=(i-d)**2
print(c)