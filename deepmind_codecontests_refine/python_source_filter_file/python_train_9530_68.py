n = int(input())
output = 'NO'
for _ in range(n):
    handle, pre, post = list(input().split())
    pre = int(pre)
    post = int(post)
    if 2400 < pre < post:
        output = 'YES'
print(output)