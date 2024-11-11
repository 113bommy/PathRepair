q = int(input())
for i in range(q):
    n, a, b = map(int, input().split())
    if a * 2 <= b:
        print(int(a*n))
    elif n % 2 == 0:
        print(int(b*n/2))
    else:
        print(int((n-1)*(b/2)+a))