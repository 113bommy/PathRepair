n=int(input())
d=[int(i) for i in input().split()]
d.sort()
print(d[n//2+1]-d[n//2])
