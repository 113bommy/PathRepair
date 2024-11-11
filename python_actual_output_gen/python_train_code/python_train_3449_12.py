n=int(input())
l=list(map(int,input().split()))
k=0
for x in l:
    if x%2: k+=1
if k==n and n!=1: print(0)
elif k%2: print(k)
else: print(n-k)