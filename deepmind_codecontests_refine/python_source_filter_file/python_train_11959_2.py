while True:
    num = int(input())
    if not num: break
    result, tmp = 0, 0
    for _ in range(num):
        new = int(input())
        tmp = max(new, new+tmp)
        result = max(tmp, result)
    print(result)