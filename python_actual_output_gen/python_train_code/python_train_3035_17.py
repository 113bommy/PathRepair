x,k=map(int,input().split())
mod=1000000007
print((pow(2,k+1,mod)*x-pow(2,k,mod)+1) if x>0 else 0)