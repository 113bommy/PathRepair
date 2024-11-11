import sys
input = sys.stdin.readline
ins = lambda: input().rstrip()
ini = lambda: int(input().rstrip())
inm = lambda: map(int, input().rstrip().split())
inl = lambda: list(map(int, input().split()))
out = lambda x, s='\n': print(s.join(map(str, x)))

n = ini()
count = (n*(n+1)//2) // 2
ans = []
for i in range(n, 0, -1):
    if count >= i:
        count -= i
        ans.append(i)
    if count == 0:
        break
if (n*(n+1)//2) & 2 == 0:
    print(0)
    print(len(ans), *ans)
else:
    print(1)
    print(len(ans), *ans)