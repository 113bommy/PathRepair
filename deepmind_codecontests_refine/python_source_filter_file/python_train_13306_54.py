L=int(input())
for i in range(1,21):
    if 2**i>L+1:
        N=i
        break
M=2*(N-1)
l=[]
for i in range(1,N):
    l.append((i,i+1,2**(i-1)))
    l.append((i,i+1,0))
L-=2**(N-1)-1
t=2**(N-1)
for i in range(N-1,-1,-1):
    if 2**i<=L:
        l.append((i+1,N,t))
        L-=2**i
        t+=2**i
        M+=1
print(N,M)
for i in l:
    print(*i)