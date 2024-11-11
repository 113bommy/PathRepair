A, B, C, D = map(int, input().split())
print('Yes' if -(-D//B) <= -(-A//C) else 'No')