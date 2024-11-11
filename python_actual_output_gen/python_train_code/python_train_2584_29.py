N,Q=map(int,input().split())
S=input()

s=[0]

for i in range(len(S)):
    s.append(s[-1]+(1 if(S[i:i+2]=="AC") else 0))

for i in range(Q):
    r,l=list(map(int,input().split()))
    print(s[r-1]-s[l-1])