t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    ans = [1, s]
    for k in range(1, n):
        new_s = s[k:]
        if n % 2 == k % 2:
            new_s += s[:k]
        else:
            new_s += s[k - 1::-1]
        if new_s < ans[1]:
            ans = [k + 1, new_s]
    print(ans[1])
    print(ans[0])
