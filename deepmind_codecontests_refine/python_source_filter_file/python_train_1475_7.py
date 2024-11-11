n,a,now = int(input()), sorted(list(map(int,input().split()))),0
for i in range(n): now += 1 if a[i] >= now else 0
print(now-1)
