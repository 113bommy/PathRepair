import sys
sys.setrecursionlimit(10**8)
T=int(input())

def solve(N):
    if N==0:
        return 0
    if N==1:
        return D
    if N in dic:
        return dic[N]
    tmp=N*D    
    if N%2==0:
        tmp=min(tmp,solve(N//2)+A)
    else:
        tmp=min(tmp,solve((N-1)//2)+A+D,solve((N+1)//2)+A+D)
    if N%3==0:
        tmp=min(tmp,solve(N//3)+B)
    else:
        b=N%3 
        tmp=min(tmp,solve((N+(3-b))//3)+B+D,solve((N-b)//3)+B+2*D)
    if N%5==0:
        tmp=min(tmp,solve(N//5)+C)
    else:
        c=N%5
        tmp=min(tmp,solve((N-c)//5)+C+D*c,solve((N+(5-c))//5)+C+D*(5-c))
    dic[N]=tmp
    return tmp

for _ in range(T):
    N,A,B,C,D=map(int,input().split())
    dic={}
    print(solve(N))
