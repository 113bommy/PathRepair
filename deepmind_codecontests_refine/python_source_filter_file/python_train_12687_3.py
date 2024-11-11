A = []
B = []
while True:
    try:
        x,y = map(int,input().split(','))
        A.append(x)
        B.append(y)
    except EOFError:
        break

N = len(A)
print(sum(A [i] * B [i] for i in range(N)),sum(B) * 2 // N - sum(B) // N)