A, B = map(int, input().split())
A = (A + 13) % 15
B = (B + 13) % 15
print('Alice' if A > B else 'Bob' if B > A else 'Draw')