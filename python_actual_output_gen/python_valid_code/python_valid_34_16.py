n, d = map(int, input().split())
s = input()
start = 0
end = 1
hear = 0
MIN = 0
while end < n-1:
    while end-start < d:
        end+=1
        if s[end] == '1':
            hear = end
            if end == n-1:
                break
    if start - hear != 0:
        end = hear
        start = end
        MIN+=1
    else:
        print('-1')
        break
if end == n-1:
    print(MIN)