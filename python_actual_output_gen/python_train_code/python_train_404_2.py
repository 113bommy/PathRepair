from sys import stdin
n=int(stdin.readline().rstrip())
l=list(map(int,stdin.readline().split()))
k=0
w=0
for i in range(n):
    w+=l[i]
    if l[i]>1:
        w+=(l[i]-1)*k
        k+=(l[i]-1)
print(w)