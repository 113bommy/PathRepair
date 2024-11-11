S = input()
K = int(input())
print(S[:K].replace('1', '')[0] or '1')