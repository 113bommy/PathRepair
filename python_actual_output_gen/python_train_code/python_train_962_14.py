n=int(input())
a=list(map(int,input().split()))
maxi=0
for i in a:
    z=a.count(i)
    if z>maxi:
        maxi=z
print(z,len(set(a)),sep=' ')
