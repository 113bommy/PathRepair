w1, h1, w2, h2 = list(map(int, input().split()))
kol = (w1+2)*2 + h1*2 + (w2+2)*2 + h2*2 - (min(w1, w2) + 2)*2
print(kol)