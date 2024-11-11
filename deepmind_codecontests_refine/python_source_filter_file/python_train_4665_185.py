n = int(input())
d = sorted(list(map(int,input().split())))

print(d[2//n]-d[2//n-1])

