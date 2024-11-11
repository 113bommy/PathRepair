n = int(input())
v = list(map(int, input().split()))
vid = -10**10
for i in range(n, 2, -1):
    if n % i == 0:
        for j in range(i):
            vid = max(vid, sum(v[j::n//i]))
print(vid)