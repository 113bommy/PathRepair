n = int(input())
maxl1 = 0
minr1 = 100000000000000
for _ in range(0,n):
    a,b = map(int,input().split())
    maxl1 = max(a,maxl1)
    minr1 = min(b,minr1)

n = int(input())
maxl2 = 0
minr2 = 100000000000000
for _ in range(0,n):
    a,b = map(int,input().split())
    maxl2 = max(a,maxl2)
    minr2 = min(b,minr2)

print(maxl1,minr1,maxl2,minr2)

print(max(max(0, maxl1-minr2), max(0, maxl2-minr1)))
