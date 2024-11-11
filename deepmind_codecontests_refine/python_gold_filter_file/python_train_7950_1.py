from fractions import Fraction
x,y,n = map(int, input().split())
ans = Fraction(x,y).limit_denominator(n)
if ans == int(ans):
	ans = str(ans) + "/1"
print(ans)