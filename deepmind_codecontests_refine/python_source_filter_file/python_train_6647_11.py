n = int(input())
a = list(map(int, input().split()))
sa = sum(a)
stone = n*(n+1)//2
if sa % stone:
    print("NO")
    exit()
a.append(a[0])
k = sa//stone
d = [a[i+1]-a[i] - k for i in range(n)]
for i in d:
    if i%n:
        print("NO")
        exit()
print("YES")