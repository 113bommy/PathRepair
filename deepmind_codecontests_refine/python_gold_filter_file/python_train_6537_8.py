n=int(input())
b=[10**18]+list(map(int,input().split()))+[10**18]
a=[0]*n
for i in range(n):
  a[i]=min(b[i],b[i+1])
print(sum(a))