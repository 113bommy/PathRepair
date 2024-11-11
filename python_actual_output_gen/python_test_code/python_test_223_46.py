n,v = map(int, input().split())
req = n-1
req -= min(n,v)
result = min(n,v)

for i in range(2,n):
    if req>0:
        result += i
        req -= 1
    else:
        break
print(result)