n,m = map(int, input().split())
print(m//2 if n*2>=m else n + (m-n*2)//4)
