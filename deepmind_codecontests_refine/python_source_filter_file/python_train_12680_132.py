S = input()


print('YES' if 15 - sum(s=='x' for s in S) <= 7 else 'NO')