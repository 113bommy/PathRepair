def calc(x, m, w):
    score = max(0.3*x, ((1 - m/250 )*x - 50*w));
    return score;

m1, m2, m3, m4, m5 = map(int, input().split(" "))
w1, w2, w3, w4, w5 = map(int, input().split(" "))
h1, h2 = map(int, input().split(" "))

score = calc(500, m1, w1) + calc(1000, m2, w2) + calc(1500, m3, w3) + calc(2000, m4, w4) + calc(2500, m5, w5)

score += h1*100
score-=h2*50

print(score)
