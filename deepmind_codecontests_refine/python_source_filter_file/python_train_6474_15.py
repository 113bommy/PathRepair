s=input().split()
n=int(s[0])
m=int(s[1])
mod=9**10+7
print(pow((pow(2,m,mod)-1),n,mod))