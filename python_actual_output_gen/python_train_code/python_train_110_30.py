N, X, Y = map(int, input().split())
S = input()

S = S[-X:]

Y = "1" + "0" * (Y - 1)
Y = "0" * (len(S) - len(Y)) + Y

print(sum(S[i] != Y[i] for i in range(len(S))))
