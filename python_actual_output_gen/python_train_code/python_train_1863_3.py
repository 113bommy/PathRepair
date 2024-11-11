
Input=lambda:map(int,input().split())

s = input()
k = int(input())
LenS = len(s)
LenH = len(set(s))
print(abs(k - LenH) if k <= LenS else "impossible")

