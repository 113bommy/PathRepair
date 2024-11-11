input()
a = list(map(int, input().split()))
ans = 0
ai = 0
while all(ai%2==0 for ai in a):
    a = [ai/2 for i in a]
    ans += 1
print(ans)