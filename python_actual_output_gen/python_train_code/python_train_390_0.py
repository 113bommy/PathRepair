n = int(input())
ans = [8,6,4,2,0]
if n == 0:
    print(1)
else:
    print(ans[(n-1) % 5])
