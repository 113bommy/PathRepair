X = input()
Left = "".join(reversed(X[0:X.index("^")]))
Right = X[X.index("^") + 1:]
ValueLeft = sum(((i + 1) * int(Left[i]) if Left[i] != "=" else 0) for i in range(len(Left)))
ValueRight = sum(((i + 1) * int(Right[i]) if Right[i] != "=" else 0) for i in range(len(Right)))
print("Left" if ValueLeft > ValueRight else ("Right" if ValueRight > ValueLeft else "balance"))
