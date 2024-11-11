n=int(input())
L=[]
S=0
for k in range(n):
    L.append(0)
for k in range(n-1):
    a,b=map(int,input().split())
    L[a-1]+=1
    L[b-1]+=1
for k in range(n):
    S+=L[k]*(L[k]-1)/2
print(S)
