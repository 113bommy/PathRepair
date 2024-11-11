n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
do = True
cnt = [0]*5
ans = 0
for i in range(n):
    cnt[a[i]-1] += 1
    cnt[b[i]-1] -= 1

for i in range(5):
    if cnt[i] % 2 == 1:
        do = False
        break

if not do:
    print('-1')
else:
    for i in range(5):
        ans += abs(cnt[i])
    
    print(ans//4)