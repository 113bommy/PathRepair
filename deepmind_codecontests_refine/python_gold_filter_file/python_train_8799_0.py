n, m, k = map(int, input().split())
pos = list(map(int, input().split()))
d = 0
for i in range(n):
    for a in list(map(int, input().split())):
        for j in range(k):
            if pos[j] == a:
                del(pos[j])
                pos = [a] + pos
                d += j + 1
print(d)
                
