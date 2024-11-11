# 解説AC
from fractions import gcd
def judge(A,B,C,D):
    """
    在庫数をXとする。
    C < X < B のときFalse
    p,qを0以上の整数とすると、
    X = A + D * p - B * q 
    X = A % G + k * G

    C + 1 <= X
    -> k = ceil((C + 1 - A % G) / G)
    """

    if A < B: return False
    if D < B: return False
    if C >= B: return True
    
    G = gcd(B, D)

    k = (C - (A & G) + G) // G
    return False if ((A % G + k * G) < B) else True

T = int(input())
for _ in range(T):
    A,B,C,D = map(int, input().split())
    if judge(A,B,C,D): print('Yes')
    else: print('No')