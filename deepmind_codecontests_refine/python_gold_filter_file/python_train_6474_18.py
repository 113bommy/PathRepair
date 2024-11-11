s=input().split()
n=int(s[0])
m=int(s[1])
mod=10**9+7
print(pow((pow(2,m,mod)-1),n,mod))