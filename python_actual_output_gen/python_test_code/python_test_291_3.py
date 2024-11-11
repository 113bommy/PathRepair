q = int(input())
for test in range(q):
    k,n,a,b = map(int, input().split(" "))
    num = k - n*b
    den = a-b
    if num <= 0:
        print(-1)
    elif num % den == 0:
        print(min(n,num//den - 1))
    else:
        print(num//den)
    