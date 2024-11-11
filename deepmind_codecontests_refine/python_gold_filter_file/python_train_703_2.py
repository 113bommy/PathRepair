n, m = map(int, input().split())
x = [list(map(int, input().split())) for i in range(m)]
for i in range(10**(n-1) if n>1 else 0, 10**n):
    i = str(i)
    for s, c in x:
        if i[s-1] != str(c):
            break
    else:
        print(i)
        exit()
print(-1)