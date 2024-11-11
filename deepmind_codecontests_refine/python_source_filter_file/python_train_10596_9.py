N,K=map(int,input().split())
c=0
while N/K>=1:
    N=N/K
    c+=1
print(c)