n = int(input())
A = set(input())
if n == 1 or n > 26:
    print('Yes')
    exit()
print(A)
if len(A) == n:
    print('No')
else:
    print('Yes')