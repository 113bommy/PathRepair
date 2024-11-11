n=int(input())
seq=[int(x) for x in input().split()]
d=0
for i in range(n):
    for j in range(i,n):
        d=max(d,j-i+1-2*sum(seq[i:j+1]))
print(sum(seq)+d)