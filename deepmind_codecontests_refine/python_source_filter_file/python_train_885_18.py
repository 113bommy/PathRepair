n = int(input())
a = int(input())
b = int(input())
c = int(input())
if n > b:
    if b - c > a:
        print(n // a)
    else:
        answer = (n - b) // (b - c)
        n = b + (n - b) % (b - c)
        cnt = 1
        cnt = max(cnt + (n - b + c) // a, n // a)
        print(answer + cnt)
else:
    print(n // a)