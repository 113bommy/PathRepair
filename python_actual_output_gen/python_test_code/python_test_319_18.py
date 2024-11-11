N, A, B = map(int, input().split())

if abs(A-B) % 2 == 1:
    print(min(A-1, B-1)+1+(B-A-1)//2)
else:
    print((B-A)//2)
