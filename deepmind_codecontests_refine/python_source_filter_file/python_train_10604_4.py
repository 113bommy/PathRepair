A = "CODEFESTIVAL2016"
S = input()
print(sum(1 if s == a else 0 for s, a in zip(A, S)))
