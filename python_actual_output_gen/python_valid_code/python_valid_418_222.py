A, B = map(int, input().split())

print(A + B if B & A else B - A)
