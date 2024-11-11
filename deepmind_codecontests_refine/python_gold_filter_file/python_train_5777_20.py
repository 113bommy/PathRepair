n = int(input())
a = [str(i) for i in range(2, n + 1, 2)] + [str(i) for i in range(1, n + 1, 2)]
if n in [2, 3]:
    a.pop(0)
print(len(a))
print(" ".join(a))