 
n=int(input())
d=list(map(int, input().split()))
if n==0:
    print(n)
    exit(0)
c=0
d.sort(reverse=True)
for i in range(len(d)):
    c=c+d[i]
    if c>=n:
        print(i+1)
        exit(0)
print(-1)
    