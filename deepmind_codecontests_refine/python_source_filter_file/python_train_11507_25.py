from math import factorial

def choose(n, k):
    return factorial(n) / factorial(k) / factorial(n-k)
  
a = int(input())
total = choose(a, 5) + choose(a, 6) + choose(a, 7)
print(total)