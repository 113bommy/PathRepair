n,k = map(int, input().split())

s = abs(sum(list(map(int, input().split()))))

if s%k==0:
    print(s//k)
else:
    print((s//k) + 1)