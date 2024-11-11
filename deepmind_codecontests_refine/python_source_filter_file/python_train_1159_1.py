n=int(input())
ar=list(map(int,input().split()))[:n]
ar.sort()
b=ar[:2]
c=ar[2:]
c.reverse()
print(*(b+c))
