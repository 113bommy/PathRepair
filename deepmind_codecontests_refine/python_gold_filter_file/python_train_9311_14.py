n = int(input())

sequence = list(map(int, input().split()))

max_length = 0


def divide_sequences():
    global max_length
    result = []
    cur_sequence = []

    def add_sequence_to_result():
        global max_length
        result.append(cur_sequence)
        max_length = max(len(cur_sequence), max_length)

    last_elem = 0
    for k in range(len(sequence)):
        if sequence[k] > last_elem:
            cur_sequence.append(sequence[k])
        else:
            add_sequence_to_result()
            cur_sequence = list()
            cur_sequence.append(sequence[k])

        last_elem = sequence[k]
    if len(cur_sequence) > 0:
        add_sequence_to_result()
    return result


divided_sequences = divide_sequences()

if len(divided_sequences) > 1:
    max_length += 1


def can_merge(seq_one_index, seq_two_index):
    seq_one = divided_sequences[seq_one_index]
    seq_two = divided_sequences[seq_two_index]

    if len(seq_one) == 1 or len(seq_two) == 1:
        return True

    if seq_one[-2] + 1 < seq_two[0] or seq_one[-1] + 1 < seq_two[1]:
        return True

    return False

divided_sequences_length = len(divided_sequences)


def can_merge_three(seq_one_index, seq_two_index):
    seq_one = divided_sequences[seq_one_index]
    seq_two = divided_sequences[seq_two_index]

    return seq_two[0] - seq_one[-1] > 0


for k in range(1, divided_sequences_length):
    if can_merge(k - 1, k):
        max_length = max(max_length, len(divided_sequences[k]) + len(divided_sequences[k-1])
                         )
    if len(divided_sequences[k]) == 1 and k < divided_sequences_length - 1 and can_merge_three(k - 1, k + 1):
        max_length = max(max_length, len(divided_sequences[k + 1]) + len(divided_sequences[k - 1]) + 1
                         )

print(max_length)



