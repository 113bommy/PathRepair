n = int(input())
s = [list(input()) for i in range(n)]
s += s

def ok(array):
    for i in range(1,n):
        for j in range(i):
            if array[i][j] != array[j][i]:
                return False
    return True
ans = 0
for i in range(n-1):
    if ok(s[i:i+n]):
        ans += n
print(ans)
