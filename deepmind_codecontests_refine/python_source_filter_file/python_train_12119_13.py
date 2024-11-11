n=int(input())
l=list(map(int,input().split()))
k,t=0,0
for i in range(n):
    if i == l[i]:k+=1
    elif i == l[l[i]]:t=1
if t==1:
    print(min(n,k+t+1))
else:
    print(min(n,k+ t))