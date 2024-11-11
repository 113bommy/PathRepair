import io, sys
input = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip()
 
ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

out = []
for _ in range(ii()):
    n, k = mi()
    if k % 3 or n < k:
        win = n % 3
    else:    
        n %= 3 * k + 1
        win = n % 3 or n == k
    out.append('Alice' if win else 'Bob')
print(*out, sep='\n')