a,b,c=map(int,input().split())
lis=list(range(1,min(a,b)+1))
lis=[x for x in lis if a%x==0 and b%x==0]
print(lis[c-1])
