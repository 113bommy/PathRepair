t = int(input())

for i in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    
    intv = (n // 2) + 1
    mdn = a[-intv::-intv]
    print(sum(mdn))
    