S, T = input(), input()
2 print(len(list(filter(lambda i: S[i] != T[i], range(len(S))))))