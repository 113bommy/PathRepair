n, t = map(int, input().split())
a = list(map(int, input().split()))

for i,j in enumerate(a):
    t=t-(86400-i)
    if t <= 0:
        print(j+1)
        break