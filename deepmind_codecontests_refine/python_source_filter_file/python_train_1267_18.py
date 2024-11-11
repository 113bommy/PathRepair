n, x, y = map(int, input().split())
inf = 10**9
a = [inf]*7 + list(map(int, input().split())) + [inf]*7

for i in range(7, n+7):
    if a[i] < (min(a[i-x:i]) if x else inf) and a[i] < (min(a[i+1:i+y+1]) if y else inf):
        print(i-6)
        exit()
