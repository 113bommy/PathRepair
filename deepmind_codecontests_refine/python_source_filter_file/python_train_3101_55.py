a, b, c = map(int, input().split())
if c>=b>=a and (c-(a+b))*(c-(a+b))-4*a*b>0: print('Yes')
else: print('No')