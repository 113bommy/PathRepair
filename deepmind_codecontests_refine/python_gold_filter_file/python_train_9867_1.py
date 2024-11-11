import sys
input = sys.stdin.readline

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=998244353
    A,B,C,D=MI()
    
    if A==C and B==D:
        print(1)
        exit()
    
    F=[[0]*(D+1) for _ in range(C+1)]
    
    def calc(a,b):
        temp=F[a][b-1]*a + F[a-1][b]*b - F[a-1][b-1]*(a-1)*(b-1)
        return temp%mod
    
    F[A][B]=1
    for i in range(A+1,C+1):
        F[i][B]=(F[i-1][B]*B)%mod
    for j in range(B+1,D+1):
        F[A][j]=(F[A][j-1]*A)%mod
    

    
    for i in range(A+1,C+1):
        for j in range(B+1,D+1):
            F[i][j]=calc(i,j)
            
 
    
    print(F[C][D])



    
    
 

main()
