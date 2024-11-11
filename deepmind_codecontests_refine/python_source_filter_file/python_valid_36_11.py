t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print('a')
        continue
    ans = 'a' * (n//2)
    if n % 2 == 0:
        ans += 'bc'
    else:
        ans += 'b'
    ans += 'a' * (n//2 + 1)
    print(ans)
    