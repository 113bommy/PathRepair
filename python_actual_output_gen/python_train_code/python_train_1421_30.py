data = input().split()

A, B, C, D = int(data[0]), int(data[1]), int(data[2]), int(data[3])

misha_scores = max((3*A)/10, (A/250) * C)
vasya_scores = max((3*B)/10, (B/250) * D)

if misha_scores > vasya_scores:
    print('Misha')
elif misha_scores < vasya_scores:
    print('Vasya')
else:
    print('Tie')
