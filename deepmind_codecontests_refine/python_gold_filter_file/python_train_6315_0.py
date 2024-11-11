def read(): return(list(map(int, input().strip().split(" "))))
n,m = read(); arr = []
for i in range(m):
    s, d, c = read()
    arr.append([s,d,c,i])
arr.sort(key = lambda arr: arr[1])
ans = [0]*(n+1)
for elem in arr:
    s, d, c, ind = elem
    for i in range(s, d):
        if ans[i] == 0:
            ans[i] = ind+1
            c -= 1
            if c == 0:
                break
    if c > 0:
        ans = [0, -1]
        break
    ans[d] = m+1
print(*ans[1:])