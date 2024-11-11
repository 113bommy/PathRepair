t = int(input())
for _ in range(t):
    input() 
    test = input()
    sum(n != k for (n, k) in zip(test, sorted(test)))