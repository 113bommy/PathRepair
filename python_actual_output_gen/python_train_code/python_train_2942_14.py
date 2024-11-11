n = int(input())
a = list(map(int,input().split()))
count = a.count(a[0])
if count == 2*n:
    print("No")
else:
    a.sort()
print(*a)