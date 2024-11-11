def get_ints():
    return list(map(int, input().split()))
 
valid = True
m = 1e9
for _ in range(int(input())):
    x,y = get_ints()
    j = max(x,y)
    if j <= m:
        m = j
    elif min(x,y)<=m:
        m = min(x,y)
    else:
        valid = False
        break
print("YES" if valid else "NO")