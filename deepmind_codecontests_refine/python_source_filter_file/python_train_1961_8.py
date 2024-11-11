n=list(map(int,input()))
s=sum(n)
k=len(n)
print(max(n[0]-1)+9*(k-1),s)