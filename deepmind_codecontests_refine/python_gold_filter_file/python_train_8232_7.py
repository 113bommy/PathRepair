n,h,a,b,k = map(int,input().split())
def abs(a,b):
	if a>b:
		return a-b
	else:
		return b-a
for i in range(k):
	ta,fa,tb,fb = map(int,input().split())
	if ta  == tb:
		print(abs(fa,fb))
	elif a <= fa and b >= fb or a >= fa and a<=fb or a>=fb and a<=fa or b >= fa and b <= fb or b>= fb and b<=fa:
		print(abs(fa,fb)+abs(ta,tb))
	elif a >= fa and a>=fb:
		print(abs(a,fa)+abs(a,fb)+abs(ta,tb))
	elif b <=  fa and b<=fb:
		print(abs(b,fa)+abs(b,fb)+abs(ta,tb))