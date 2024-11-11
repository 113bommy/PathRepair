n = int(input())
a = sorted((input() for _ in range(n)),key = lambda x : len(x))
ok = all(a[i] in a[i+1] for i in range(n-1))
print('YES'+"\n".join(a) if ok else 'NO')