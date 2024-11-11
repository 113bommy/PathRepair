from fractions import Fraction
m = list(map(Fraction, input().split()))
w = list(map(Fraction, input().split()))
h1,h2 = map(Fraction, input().split())
ball = [500,1000,1500,2000,2500]
score = Fraction(0)
for i in range(5):
	score += max(Fraction(3,10)*ball[i],(1-Fraction(m[i],250)*ball[i])-50*w[i])
score += h1*100-50*h2
print(int(score))
