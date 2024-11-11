

f0 = "What are you doing at the end of the world? Are you busy? Will you save us?"
first_part = 'What are you doing while sending "'
between1 = '"? Are you busy? Will you send "'
f_lengths = [0 for i in range(64)]
f_lengths[0] = len(f0)
for i in range(1, 64):
    f_lengths[i] = 2*f_lengths[i-1] + 68

# print(f_lengths)

def determine_n(n, k):
    while n > 64 and k >= 34:
        k -= 34
        n -= 1
    return n

# k is 0 based here
def index_find(n, k) -> str:
    print("index_find(n, k): ", n , k)
    if n == 0:
        if k >= len(f0):
            return "."
        return f0[k]

    if k < 34:
        return first_part[k]

    first_end = 34 + f_lengths[n-1]
    if 34 <= k < first_end:
        return index_find(n-1, k-34)
    if first_end <= k < first_end + 32:
        return between1[k-first_end]
    second_end = f_lengths[n-1] + first_end + 32
    if first_end + 32 <= k < second_end:
        return index_find(n-1, k-first_end-32)
    else:
        if k - second_end > 1:
            return '.'
        return '"?'[k - second_end]

n = int(input())
queries = [map(int, input().split()) for i in range(n)]
r = []

for n, k in queries:
    # print(k, n)

    if n > 64:
        new_n = determine_n(n, k-1)
        prefix = (n - new_n) * 34
        r.append(index_find(new_n, k-1-prefix))
    else:
        r.append(index_find(n, k-1))

print("".join(r))




