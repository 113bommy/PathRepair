n=int(input())
l=list(map(int,input().split()))
max=l[0]
c=0
for x in l:
    if max <x:
        max=x
    else:
        c+=(max-x)
print(c)
