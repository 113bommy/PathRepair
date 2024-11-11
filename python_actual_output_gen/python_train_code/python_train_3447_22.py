b = int(input())
g = int(input())
n = int(input())
ans = 0
if n == b+g: ans = 1
else:
    if max(b,g)<n:
        ans = min(b,g)
    else:
        ans = min(b,g,n)+1
print(ans)
