a = int(input())
b = list(map(int,input().split()))
b.sort()
c  = 1
yon = 10**18
for i in b:
    c *= i
if c > yon :
    print(-1)
    exit()
print(c)