A, B, C, X = [int(input()) for i in range(4)]
print(sum(100*a + 50*b + 10*c == X for a in range(A+1) for b in range(B+1) for c in range(C+1)))