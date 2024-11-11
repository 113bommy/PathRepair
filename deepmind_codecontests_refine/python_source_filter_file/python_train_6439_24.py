A, B = map(int, input().split())
A = (A + 12) % 13
B = (B + 12) % 13
print('Alice' if A > B else ('Bob' if B > A else 'Draw'))