n = int(input())
a = list()
for i in range(n):
    score = int(input())
    if score <= 7:
        a.append(1)
        continue
    else:
        k = score/2
        if score % 2 == 0:
            a.append(int(k))
        else:
            a.append(int(k)+1)

for e in a:
    print(e)
