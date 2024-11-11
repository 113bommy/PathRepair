queue, initial = list(map(int, input().split()))
distress = 0


for x in range(queue):
    ca = list(input().split())
    if ca[0] == '+':
        initial += int(ca[1])
    if ca[0] == '-' and int(ca[1]) > initial:
        distress += 1
    if ca[0] == '-' and int(ca[1]) < initial:
        initial -= int(ca[1])





print(initial, distress)

