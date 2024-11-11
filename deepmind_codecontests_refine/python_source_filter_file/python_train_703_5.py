n, m = map(int, input().split())
sc = [list(map(int, input().split())) for i in range(m)]
for i in range(0, 10**n):
    if len(str(i)) == n and all(str(i)[s-1] == str(c) for j in sc):
        print(i)
        break
else:
    print(-1)