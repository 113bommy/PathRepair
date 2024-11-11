n=int(input())
a=[int(input()) for i in range(0,n)]
j=0
ans=-1
for i in range(0,n):
    if a[j] == 2:
        ans = j
        break
    j = a[j]-1

print(ans)