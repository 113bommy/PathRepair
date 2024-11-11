S = input()

print('YES' if sum(s=='o' for s in S) >= 8 else 'NO')