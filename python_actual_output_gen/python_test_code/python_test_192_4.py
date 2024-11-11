n,s = list(map(int ,input().split()))

a = list(map(int, input().split()))

a.sort(reverse = True)

t = 0

for i in range(1,n) :
    t = 0
    for j in range (n) :
        t += max(0, a[j] - j//i)
    if t >= s :
        print(i)
        exit(0)
print(-1)

