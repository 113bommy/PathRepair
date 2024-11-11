n = int(input())
button = list(input().split())

if n == 1:
    if button[0] == '1':
        print("YES")
    else:
        print("NO")
else:
    c = 0
    for i in button:
        if i == '1':
            continue
        else:
            c += 1
    if c <= 1:
        print("YES")
    else:
        print("NO")
