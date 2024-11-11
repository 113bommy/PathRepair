for _ in range(int(input())):
    n, m = map(int, input().split())
    a = n//m
    li = []
    for i in range(1, 11):
        li.append((m*i)%10)
    b = sum(li)
    s = b*(a//10) + sum(li[:a%10])
    print(s)