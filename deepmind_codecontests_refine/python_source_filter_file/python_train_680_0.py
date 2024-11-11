n = int(input())
a = list(map(int, input().split()))
k = int(input())
b = list(map(int, input().split()))

possible = True

i = 0
j = 0

sub_b = b.copy()

start_index_last_prefix = 0

max_on_prefix = a[start_index_last_prefix]
first_max_on_prefix_index = last_max_on_prefix_index = start_index_last_prefix
actual_finding_max = True

result = []

while possible and i < n and j < k:

    this = a[i]

    if i == start_index_last_prefix:

        max_on_prefix = a[start_index_last_prefix]
        first_max_on_prefix_index = last_max_on_prefix_index = start_index_last_prefix
        actual_finding_max = True

    if this > max_on_prefix:

        max_on_prefix = this
        first_max_on_prefix_index = last_max_on_prefix_index = i
        actual_finding_max = True

    elif this == max_on_prefix and actual_finding_max:
        last_max_on_prefix_index = i

    else:
        actual_finding_max = False

    sub_b[j] -= this

    if sub_b[j] == 0:

        if first_max_on_prefix_index != start_index_last_prefix:

            number_of_left_eat = first_max_on_prefix_index - start_index_last_prefix
            for x in range(number_of_left_eat):

                pos = number_of_left_eat - x + 1 + j
                step = 'L'
                act = str(pos) + ' ' + step

                result.append(act)

            number_of_right_eat = i - first_max_on_prefix_index
            for x in range(number_of_right_eat):

                pos = 1 + j
                step = 'R'
                act = str(pos) + ' ' + step

                result.append(act)

        elif last_max_on_prefix_index != i:

            number_of_right_eat = i - last_max_on_prefix_index
            for x in range(number_of_right_eat):

                pos = last_max_on_prefix_index - start_index_last_prefix + 1 + j
                step = 'R'
                act = str(pos) + ' ' + step

                result.append(act)

            number_of_left_eat = last_max_on_prefix_index - start_index_last_prefix
            for x in range(number_of_left_eat):

                pos = number_of_left_eat - x + 1 + j
                step = 'L'
                act = str(pos) + ' ' + step

                result.append(act)

        elif start_index_last_prefix != i:
            possible = False

        start_index_last_prefix = i + 1
        j += 1

    elif sub_b[j] < 0:
        possible = False

    i += 1

if i != n - 1 or j != k - 1:
    possible = False

if possible:
    print('YES')
    print('\n'.join(result))
else:
    print("NO")
