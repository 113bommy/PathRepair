n = int(input())
seq = []

for i in range(n+1):

    num = [int(x) for x in str(i)]

    for j in num:
        seq.append(j)

print(seq[n])
