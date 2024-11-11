n,m,k=map(int,input().split())
l=list(int(input()) for i in  range(m+1))
print(sum([bin(l[m]^y).count('1')<=k for y in l])-1)
