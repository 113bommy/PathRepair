IL = lambda: list(map(int, input().split()))
IS = lambda: input().split()
I = lambda: int(input())
S = lambda: input()

l, r, x, y, k = IL()
for i in range(max(x, l*k), min(y, r*k) + 1):
    if i%k == 0:
        print("YES")
        quit()
print("NO")