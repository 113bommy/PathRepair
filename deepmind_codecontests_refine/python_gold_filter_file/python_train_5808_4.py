import sys
sys.setrecursionlimit(1000000)

def F(S,curr,D,res):
    if D["A"]<0 or D["B"]<0 or D["C"]<0:
        return False
    if len(S)==curr:
        print("Yes")
        for c in res:
            print(c)
        #print("".join(res))
        return True
    s=S[curr]
    
    a=False
    b=False
    if D[s[0]]>=1:
        D[s[0]]-=1
        D[s[1]]+=1
        res.append(s[1])
        a=F(S,curr+1,D,res)
        res.pop(-1)
        D[s[0]]+=1
        D[s[1]]-=1
    if a:
        return a

    if D[s[1]]>=1:
            D[s[1]]-=1
            D[s[0]]+=1
            res.append(s[0])
            b=F(S,curr+1,D,res)
            res.pop()
            D[s[1]]+=1
            D[s[0]]-=1
    return a or b


N,A,B,C=map(int,input().strip().split())
D={"A":A,"B":B,"C":C}
S=[]
res=[]
for i in range(N):
    S.append(input())
if not (F(S,0,D,res)):
    print("No")