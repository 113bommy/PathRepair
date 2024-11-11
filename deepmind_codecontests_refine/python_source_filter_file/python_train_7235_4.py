n=int(input())
l=list(map(int,input().split()))
s=l[0]
for i in range(1,n):
    s+=abs(l[i]-l[i-1])
print(s)
