n=int(input())
p=list(map(int,input().split()))
d={x-1:i for i,x in enumerate(p)}
a=[3000*i for i in range(1,n+1)]
b=[3000*(n-i)+d[i] for i in range(n)]
print(' '.join(map(str,a)))
print(' '.join(map(str,b)))