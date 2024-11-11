"""
H cm above surface of water
sailed distance of L cm, where water touched
surface

determine the depth of lake

"""
from decimal import *
getcontext().prec = 30
H,L= map(int,input().split())
k=Decimal(Decimal((L**2-H**2)*(10**7))/Decimal(2*H))
print(k)
