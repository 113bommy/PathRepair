l=list(map(int,input().split()))
l.sort()
k=int(input())
print(l[0]+l[1]+l[2]*2**k)