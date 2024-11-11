F=lambda*m:max(len(str(x))for x in m);print(m)
N=int(input())
print(min(F(x,N//x)for x in range(1,int(N**.5)+1)if N%x==0))