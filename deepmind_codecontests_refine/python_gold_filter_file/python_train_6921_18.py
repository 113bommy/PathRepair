n=int(input())
a=list(map(int,input().split()))
a.sort()
p=0
di=0
for i in range(n):
    if p<=a[i]:
        p+=a[i]
        di+=1
print(di)