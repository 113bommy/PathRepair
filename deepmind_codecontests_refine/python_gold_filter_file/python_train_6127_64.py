n, m = map(int, input().split())

print(m//2 if n >= m//2 else n+(m-n*2)//4)