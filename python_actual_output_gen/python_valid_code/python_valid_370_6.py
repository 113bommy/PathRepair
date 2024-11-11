# for testCase in range(int(input())):
n ,m = map(int ,input().split())
ans = cnt = 0
while m:
    s = input()
    if s.find('0'):
        cnt += 1
    else:
        cnt = 0
    ans = max(ans ,cnt)
    m -= 1
print(ans)
