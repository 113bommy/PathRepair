n = int(input())
A = map(int, input().split())
 
ai = max(A)
A.remove(ai)
 
Asub = [abs(ai/2 -a) for a in A]
aj = A[Asub.index(min(Asub))]
 
print('{} {}'.format(ai, aj))