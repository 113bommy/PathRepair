t = input()
p = [t] + [int(t) - int(t[k:]) - 1 for k in range(1, len(t))]
print(max(p, key=lambda q: sum(map(int, str(q)))))