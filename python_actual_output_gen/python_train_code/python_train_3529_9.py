def compute():
    A, B, n, x = map(int,input().split())
    MOD = int(1e9+7)
    i = (pow(A,n,MOD)*x)%MOD
    if A==1: j = B*(n-1)
    else: j = (B*(pow(A,n,MOD)-1)*(pow(A-1,MOD-2,MOD)))%MOD
    return str((i+j)%MOD)

if __name__=="__main__":
    print(compute())
