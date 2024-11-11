A, B = [s == "H" for s in input().split()]

print(["D", "H"][A ^ B])