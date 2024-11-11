n = int(input())
a = " ".join([" ".join([str(i ** k) for k in range(1, 30) if i ** k <= n]) for i in range(2, n + 1) if all([i % j != 0 for j in range(2, i)])])
print((len(a.split())), "\n" + a)
