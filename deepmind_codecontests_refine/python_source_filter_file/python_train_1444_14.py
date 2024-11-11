def f(p, q):
    if q < p:
        return q
    else:
        return f(p, q//p) + q%p

n = int(input())
s = int(input())
flag = 0
if n < s:
    print(-1)
    flag = 1
if flag == 0 and n == s:
    print(n+1)
    flag = 1
if flag == 0:
    for i in range(2, int(n**0.5)+2):
        if f(i, n) == s:
            print(i)
            flag = 1
            break
if flag == 0:
    for i in range(int(n**0.5), 1, -1):
        if (n-s)%i == 0:
            if f((n-s)//i+1, n) == s:
                print((n-s)//i+1)
                flag = 1
                break

if flag == 0:
    print(-1)