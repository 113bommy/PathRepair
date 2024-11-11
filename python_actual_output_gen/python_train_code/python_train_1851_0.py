
s = input()
t = input()
print(['NO', 'YES'][sorted(s) == sorted(t) and sum([1 for i, j in zip(s, t) if i != j]) > 1])
