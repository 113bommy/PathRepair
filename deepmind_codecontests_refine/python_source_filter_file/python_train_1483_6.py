n, m = map(int, input().split())

l = list(map(int, input().split()))

total = sum(l)

if total<n:
    print(-1)
    exit()
    
rem = total-n

pos = 1
ans = []
for i, x in enumerate(l):
    ans += [pos]
    if pos + x > m:
        print(-1)
        exit()
    saved = min(rem, x-1)
    rem -= saved
    pos += x-saved

print(*ans)
