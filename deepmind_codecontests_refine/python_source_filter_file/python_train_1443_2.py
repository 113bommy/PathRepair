n = int(input())
A = list(map(int, input().split()))
r = n%2

d = [0]*n
for a in A:
    if a%2 == r:
        print(0)
        break
    d[a] += 1
    if (d[a] > 2) or (a == 0 and d[0] > 1):
        print(0)
        break
else:
    print(2**(n//2) % (10*9+7))