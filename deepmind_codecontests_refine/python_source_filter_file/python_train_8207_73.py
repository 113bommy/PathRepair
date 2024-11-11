n = int(input())
result, r = divmod(n, 11)
print(result*2 + 1 + (r>6))