m=[input() for _ in range(8)]
for i in range(3):
    m=list(zip(*m[::-1]))
    print(90*i)
    for x in m:
        print(''.join(x))