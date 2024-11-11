def divisors(n):
    div = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            div.append(i)
            if i**2 != n:
                div.append(n//i)
    div.sort()
    return div

n,k = map(int, input().split())
a = list(map(int, input().split()))

d = divisors(sum(a))
d.reverse()

for x in d:
    b = []
    for i in range(n):
        b.append(x-a[i]%x)
    b.sort()
    c = sum(b)//x
    if sum(b[:-c]) <= k:
        print(x)
        exit()
