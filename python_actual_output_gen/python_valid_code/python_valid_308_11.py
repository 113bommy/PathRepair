n, m = map(int,input().split())
fs = set()
for i in range(1,m):
    fs.add(i)
for i in range(n):
    a, b = map(int,input().split())
    hmmm = set()
    for i in range(a,b+1):
        hmmm.add(i)
    fs -= hmmm
print(len(fs))
print(*fs)