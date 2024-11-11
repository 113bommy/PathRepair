N = int(input())
R = []
for i in range(N):
    s, p = input().split()
    R.append((s, -int(p), i))

R.sort()
print(R)
for i in R:
    print(i[2] + 1)
