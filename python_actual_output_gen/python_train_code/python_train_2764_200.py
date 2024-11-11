s=int(input())
d=[int(x) for x in input().split()]
volume=0
for i in range(s):
    volume+=d[i]/100
print(volume/s)