[p, n] = map(str, input().split(" "))
p = int(p)
n = int(n)
arr = []
ans = -1
for i in range(n):
    inp = int(input())
    b = inp%p in arr
    if(b):
        if(ans == -1):
            ans = i+1
    arr.append(inp%p)
print(ans)

