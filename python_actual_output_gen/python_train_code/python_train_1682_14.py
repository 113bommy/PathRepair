h, w = map(int, input().split())
print(1 if h == w == 1 else (h*w+1)//2)