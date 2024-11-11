R=lambda:map(int,input().split())

h, m = R()

H, D, C, N = R()

opt1 = (H // N + ( H % N > 0))   * C

m = max(0, (20 - h) * 60 - m)

H = H + m * D

C = C /4 * 5 

opt2 = (H // N + ( H % N > 0)) * C

print(min(opt1, opt2))