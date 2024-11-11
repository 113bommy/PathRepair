import io, sys
input = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip()

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

n = ii()
a = li()
p = a.index(max(a))
b = sorted(a)
b.pop()
ok = 1
i, j = p - 1, p + 1
while i >= 0 or j < n:
    if i >= 0 and a[i] == b[-1]:
        b.pop()
        i -= 1
    elif j < n and a[j] == b[-1]:
        b.pop()
        j += 1
    else:
        ok = 0
        break
print('YES' if ok else 'NO')