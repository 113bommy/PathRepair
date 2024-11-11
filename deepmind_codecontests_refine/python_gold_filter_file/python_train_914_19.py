n=int(input())
H=list(map(int,input().split()))
c=1
for i in range(1,n):
    if max(H[:i])<=H[i]:
        c += 1
print(c)