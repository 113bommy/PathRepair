a, b, c = input().split()
print(["No", "Yes"][(a == b and b == c)::2])