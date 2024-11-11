n = int(input())
A = ['a']
S = 'abcdefghij'
for _ in range(n-1):
    A = [ a + s for a in A for s in S[:len(a) + 1]]
print('\n'.join(A))