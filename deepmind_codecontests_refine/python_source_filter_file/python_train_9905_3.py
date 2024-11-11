import sys
N = int(input())
n = N//2

A = input()
B = input()
C = [(a == '1') * 2 + (b == '1') for a, b in zip(A, B)]

w = C.count(0)
x = C.count(1)
y = C.count(2)
z = N - w - x - y
Ans = []
for i in range(x + 1):
    for j in range(y + 1):
        z1 = (y + z - i - j)
        if z1 % 2:
            continue
        z1 //= 2
        if not 0 <= z1 <= z:
            continue
        w1 = n - i - j - z1
        if not 0 <= w1 <= w:
            continue
        cnt = [w1, i, j, z1]
        ans = []
        for i, a, b in zip(range(1, N+1), A, B):
            if cnt[(a == '1') * 2 + (b == '1')] > 0:
                cnt[(a == '1') * 2 + (b == '1')] -= 1
                Ans.append(i)
        print(*Ans)
        sys.exit()
print(-1)
        
