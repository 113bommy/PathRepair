n,k=map(int,input().split(' '))
m=list(map(int,input().split(' ')))
print(int((n*k-sum(m))*2-n))