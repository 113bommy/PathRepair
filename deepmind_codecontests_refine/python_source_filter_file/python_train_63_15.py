n, k = map(int, input().split())
m = sorted(list(map(int, input().split())), reverse=True)
for i in m:
    if k % i:
        print(k // i)
        exit()
