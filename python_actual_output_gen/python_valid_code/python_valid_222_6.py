N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
src.sort(key=lambda x:x[1])

a = b = 0
for i,(x,y) in enumerate(reversed(src)):
    if i%2:
        b += y
    else:
        a += x
print(a-b)