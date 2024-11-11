n,h = map(int,input().split())
a = list(map(int,input().split()))

for i in range(n+1):
    t = sum(sorted(a[:i])[::-2])
    if t > h:
        print(i-1)
        break
else:
    print(n)
