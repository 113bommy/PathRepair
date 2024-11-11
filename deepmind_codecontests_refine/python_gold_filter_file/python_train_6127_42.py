n, m = map(int, input().split())
if n >= m//2:
    print(m//2)
else:
    print(n+(m-2*n)//4)