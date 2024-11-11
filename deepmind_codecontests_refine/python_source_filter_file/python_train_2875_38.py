IL = lambda: list(map(int, input().split()))
I = lambda: int(input())

n, k = IL()
ans1 = 1 if k%n else 0
if k==0:
    ans2 = 0
elif k*2 < n:
    ans2 = k+1
else:
    ans2 = n-k
print(ans1, ans2)