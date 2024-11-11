A, B, C = map(int, input().split())
print('Yes' if A-C>0 or C-B>0 and A-C<0 or C-B<0 else 'No')