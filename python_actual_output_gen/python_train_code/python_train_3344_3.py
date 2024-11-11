n=int(input())
l=list(map(int,input().split()))
c=0
l.sort()
for i in range(1,n):
    c+=l[i]-l[i-1]
print(c)