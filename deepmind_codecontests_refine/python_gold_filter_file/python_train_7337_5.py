'''def contains(vec, c):
    for i in range(len(vec)):
        if vec[i] == c:
            return True
    return False
'''


def different_index_starts_at(start_index, start_letters, _str):
    for index in range(start_index, len(_str)):
        # if not contains(start_letters, item):
        if _str[index] not in start_letters:
            return index

    return -1


k = int(input())
q = input()

starting_letters = [q[0]]

answer = []

start = 0
for i in range(k):
    different = different_index_starts_at(start + 1, starting_letters, q)

    if different != -1 and k != i + 1:
        starting_letters.append(q[different])
        answer.append(q[start:different])
        start = different
    else:
        answer.append(q[start:])
        break

if len(answer) == k:
    print("YES")
    for s in answer:
        print(s)
else:
    print("NO")
