n = int(input())
l = sorted([*map(int, input().split())])

for i in range(n//3):
    if not l[i]<l[i +n//3]<l[i + 2*n//3] or l[i+ n//3]%l[i]!= 0 or l[i + 2*n//3]%l[1 + n//3] != 0:
        print(-1)
        exit()

for i in range(n//3):
    print(*l[i::n//3])
exit()
    
