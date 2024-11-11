n = int(input())
d = list(map(int,input().split()))
d.sort()
print(d[int(N/2)]-d[int(N/2)-1])