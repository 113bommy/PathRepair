s = input()
k = int(input())
n = len(s)

if k == 0:
    print(1)
    exit()
if k == 1:
    print(n-1)
    exit()

st = [0, 0]
for i in range(2, 1000):
    c = 0
    for j in range(10):
        if 1 << j & i:
            c += 1
    st.append(st[c] + 1)

nums = [i for i in range(len(st)) if st[i] == k-1 and i <= n]
if len(nums) == 0:
    print(0)
    exit()
max_k = nums[-1]

c = [[0 for i in range(max_k+1)] for j in range(n+1)]
c[0][0] = 0
for i in range(n+1):
    c[i][0] = 0
for i in range(max_k+1):
    c[0][i] = 0
for i in range(1, n+1):
    c[i][1] = i
for i in range(2, n+1):
    for j in range(2, min(i+1, max_k+1)):
        c[i][j] = c[i-1][j-1] + c[i-1][j]
        c[i][j] %= 10**9 + 7

ans = 0
for num in nums:
    cnt = num
    for i in range(n):
        if s[i] == '1':
            ans += c[n-i-1][cnt]
            ans %= 10**9 + 7
            cnt -= 1
        if cnt == 0:
            ans += 1
            break
print(ans % (10**9 + 7))