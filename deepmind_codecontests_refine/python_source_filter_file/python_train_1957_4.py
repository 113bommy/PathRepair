N = int(input())
print("".join(map(lambda c: chr((c+N-65)%27+65), map(ord, input()))))