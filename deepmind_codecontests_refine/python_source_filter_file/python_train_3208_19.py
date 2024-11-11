n=int(input())
s=set()
for i in range(1,n+1):
    if n%2==0:
        s.add((i,n-i))
    else:
        s.add((i,n+1-i))
m=len(s)
print(n*(n-1)//2-m)
for i in range(1,n+1):
    for j in range(i+1,n+1):
        if (i,j) in s:
            pass
        else:
            print(i,j)