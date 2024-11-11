f=lambda x:int(x)%2
n=int(input())
a=list(map(f,input().split())).count(1)
print([YNEOS][n>1 and a%2>0::2])