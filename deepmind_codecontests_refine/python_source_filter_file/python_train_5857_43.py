
t = int(input())

for _ in range(t):
    n, r = [int(i) for i in  input().split()]
    count = 0 
    if r >=n:
        r = n - 1
        count += 1
    count = ((2+(r-1))* r) // 2
    print(count)
