N,Q=map(int,input().split())
S=input()
c=[0]
t = 0
for i in range(1,N):
    t += 1 if  S[i-1:i+1]=='AC' else 0
    c.append(t)
for _ in range(Q):
    l,r=map(int, intput().split))
    print(c[r]-c[l])
