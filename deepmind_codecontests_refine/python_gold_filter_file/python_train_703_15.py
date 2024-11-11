n,m=map(int,input().split())
N="a"*n
for _ in range(m):
    s,c=map(int,input().split())
    s-=1
    if (s==0 and c==0 and n!=1) or (N[s]!="a" and N[s]!=str(c)):
        print(-1)
        exit()        
    else:
        N=N[:s]+str(c)+N[s+1:]
if N[0]=="a" and n!=1:N="1"+N[1:]
N=N.replace("a","0")
print(int(N))