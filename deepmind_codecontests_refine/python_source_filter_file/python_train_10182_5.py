import sys
input=sys.stdin.readline
n=int(input())
A=tuple(map(int,input().split()))
B=tuple(map(int,input().split()))

def exchange(n,A,B):
    R=[]
    for a,b in zip(A,B):
        if a<b:
            R.append((a,b))
    if len(R)==0:
        return n
    if len(R)==1:
        a,b=R[0]
        return n+n//a*(b-a)
    if len(R)==2:
        a0,b0=R[0]; a1,b1=R[1]
        ans=n
        s=n//a0
        for i in range(s+1):
            p=b0*i
            q=n-a0*i
            r=q//a1
            ans=max(ans,a+q+r*(b1-a1))
        return ans
    a0,b0=R[0]; a1,b1=R[1]; a2,b2=R[2]
    ans=n
    s=n//a0
    for i in range(s+1):
        p=n-a0*i
        t=p//a1
        for j in range(t+1):
            q=p-a1*j
            ans=max(ans,b0*i+b1*j+q+q//a2*(b2-a2))
    return ans

n=exchange(n,A,B)
print(exchange(n,B,A))