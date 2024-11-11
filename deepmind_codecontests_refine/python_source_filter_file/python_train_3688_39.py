'''Author:  Abdurasul !!!'''
n=int(input());s=0
a=list(map(int,input().split()))
k,l=map(int,input().split())
for i in range(l-1):s=s+a[i]
print(s)
