n=int(input())
l=list(map(int,input().split()))
k,t=0,0
for i in range(n):
    if i == l[i]:k+=1
    elif i == l[l[i]]:t=1
print(k+1+t) 