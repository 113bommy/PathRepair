a, b, c, d = map(int, input().split())
try:
    assert abs(a - b + c - d) < 2
    ans = []
    if not d:
        ans = [1, 0] * a + [1, 2] * c
        if a + c < b:
            ans.append(1)
        if a + c > b:
            ans.pop(0)
    elif not a:
        ans = [2, 3] * d + [2, 1] * c
        if d + b < c:
            ans.append(2)
        if d + b < c:
            ans.pop(0)
    elif a + c > b + d:
        while a:
            ans.append(0)
            ans.append(1)
            a -= 1
            b -= 1
        assert b >= 0
        while b:
            ans.append(2)
            ans.append(1)
            b -= 1
            c -= 1
        assert c >= 0
        while c:
            ans.append(2)
            ans.append(3)
            c -= 1
            d -= 1
        ans.pop()
    else:
        while d:
            ans.append(3)
            ans.append(2)
            c -= 1
            d -= 1
        assert c >= 0
        while c:
            ans.append(1)
            ans.append(2)
            b -= 1
            c -= 1
        assert b >= 0
        while b:
            ans.append(1)
            ans.append(0)
            a -= 1
            b -= 1
        if a:
            ans.pop()
    print("YES")
    print(*ans)
except AssertionError:
    print("NO")
