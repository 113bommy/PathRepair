T=int(input())
l=list(map(int,input().split()))
l.sort()
l.reverse()
a=0
while sum(l[a:])>sum(l[:a]):
    a+=1
print(a)