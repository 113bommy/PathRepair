n = int(input())
t = list(map(int, input().split()))
a = sorted([t[i], i+1] for i in range(n))
print(a)
for i in range(n//2):
    print(a[i][1],a[-i-1][1])