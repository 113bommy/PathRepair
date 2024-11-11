n,q=map(int,input().split())
S=input()
L=[0]
c=0
for i in range(n-1):
    if S[i:i+2]=='AC':
        c+=1    
    L.append(c)
print(L)
for j in range(q):
    s,e=map(int,input().split())
    print(L[e-1]-L[s-1])