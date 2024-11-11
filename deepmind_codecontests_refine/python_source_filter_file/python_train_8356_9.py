import bisect, math

def foo(n):
    mx = n//3 +1
    for i in range(mx):
        for j in range(mx):
            v = i*3 + j*7
            if (n-v)%5==0:
                return i, int((n-v)//5), j
    return -1, 

t = int(input())
for _ in range(t):
    n = int(input())
    print(" ".join(map(str, foo(n))))
    