A,B = map(int,input().split())
x = A + B if A % B == 0 else B - A
print(x)