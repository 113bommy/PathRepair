n, *l = int(input()), *map(int, input().split())
p = sum(a % 2 for a in l[:3]) == 2
print(*list(i+1 for i in range(len(l)) if l[i] % 2 != p))