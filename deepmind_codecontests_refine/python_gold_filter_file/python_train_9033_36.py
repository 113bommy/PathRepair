n,k=map(int,input().split(' '))
l=list(map(int, input().split(' ')))
l=sorted(l)
 
print(sum(l[:max(n-k,0)]))