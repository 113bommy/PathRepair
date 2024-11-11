n = int(input())
result, r = divmod(n-1, 11)
r += 1
print(result*2 + 1 + (r>6))