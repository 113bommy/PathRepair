S = input()
K = int(input())
print(S[:K].replace('1', '')[:1] or '1')
