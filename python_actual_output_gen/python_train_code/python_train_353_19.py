a,b = map(int, input().split())
c,d = map(int, input().split())
for i in range(1000 * 1000):
    if (d - b + i * c) % a == 0 and (d - b + i * c) > 0:
        print(d + i * c)
        exit(0)
print(-1)
        
