N,X = input().split()
N,X = int(N), int(X)
answer = X+ (N-X)


def rhombus(N,X):
    if X==1: 
        return N+1
    if X==0:
        return 0

    if N%X == 0:
        return X*(N//X)*2-1
      
    else: 
        k = N//X
        return k*2*X + rhombus(X,N-(k*X))

      

answer = answer + rhombus(N-X,X)
print(answer)