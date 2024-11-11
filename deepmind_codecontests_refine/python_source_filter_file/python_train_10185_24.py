A, B, C, X = [int(input()) for i in range(4)]
print(sum(500*a + 100*b + 50*c == X for a in range(A+1) and b in range(B+2) and c in range(C+1)))