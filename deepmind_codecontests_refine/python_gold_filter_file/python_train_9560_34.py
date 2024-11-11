A, B = input().split()
N = 0
for i in range(int(A), int(B)+1):
    if str(i) == str(i)[::-1]:
        N += 1
print(N)