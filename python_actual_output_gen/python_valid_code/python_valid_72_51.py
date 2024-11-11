w, h, x, y = map(int, input().split())
print(w*h/2, int(h==2**y and w==2**x))