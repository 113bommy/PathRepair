from collections import defaultdict
n = int(input())

diags1 = defaultdict(int)
diags2 = defaultdict(int)

while n:
    n -= 1
    x, y = list(map(int, input().split()))
    diags1[x+y] += 1
    diags2[x-y] += 1

# print(diags1)

ans = 0
for k, v in diags1.items():
    ans += (v*(v-1))/2

for k, v in diags2.items():
    ans += (v*(v-1))/2

print(int(ans))

