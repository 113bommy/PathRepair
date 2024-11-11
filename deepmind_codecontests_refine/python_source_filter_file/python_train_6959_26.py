n, m = int(input()), 0
for i in range(1, int(n**.5)+1):
    if not n%i%1:
        m = max(m, i)
print(len(str(n//m)))