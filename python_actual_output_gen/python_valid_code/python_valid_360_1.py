out = []
for _ in range(int(input())):
    n,u,v = map(int, input().split())
    arr = list(map(int, input().split()))
    
    hi = 0
    for i in range(n - 1):
        if abs(arr[i] - arr[i + 1]) >= 2:
            hi = -1
            break
        hi = max(hi, abs(arr[i] - arr[i + 1]))
    if hi == -1:
        out.append('0')
    elif hi == 0:
        out.append(str(u+v))
    else:
        out.append(str(min(u,v)))
print('\n'.join(out))