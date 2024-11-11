w=input()
odd=[i for i in set(w) if w.count(i)%2]
print('NO' if odd else 'YES')