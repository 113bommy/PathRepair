from sys import stdin, stdout

b, q, l, n = map(int, stdin.readline().split())
a = set(list(map(int, stdin.readline().split())))
ans = 0
ind = 0

while abs(b) <= l and ind < 100:
    if not b in a:
        ans += 1
            
    b *= q
    ind += 1
    
if ans > 50:
    stdout.write('inf')
else:
    stdout.write(str(ans))