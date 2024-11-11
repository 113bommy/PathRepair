try:
    result = result2 = count = 0
    while True:
        a, b = map(int, input().split(','))
        result += a*b
        result2 += b
        count += 1
except:
    print(result)
    print(int(round(result2/count,0)))