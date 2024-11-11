n=int(input())
l=list(map(int,input().split(' ')))
s=0
for i in range(n):
    s+=(l[i]/100)
d=s/n
print(d*100)