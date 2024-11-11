n,k=map(int,input().split(' '))
m=list(map(int,input().split(' ')))
print(max(int((n*k-sum(m))*2-n),0))