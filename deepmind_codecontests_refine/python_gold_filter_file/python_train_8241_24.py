q = int(input())
for _ in range(q):
    n, m = map(int, input().split())
    a = [m%10]
    for i in range(2, 10):
        a.append((m*i)%10)
    sum_of_10 = sum(a)
    temp = int((n - n%m)/m)
    print(int(temp/10)*sum_of_10 + sum(a[0:temp%10]))
