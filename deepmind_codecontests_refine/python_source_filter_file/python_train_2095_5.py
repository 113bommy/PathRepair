def print_answer(ans):
    import sys
    sys.stdout.write(" ".join([str(x) for x in ans]))


n, m = [int(x) for x in input().strip().split(" ")]

people = [int(x) for x in input().strip().split(" ")]
is_taxist = [int(x) > 0 for x in input().strip().split(" ")]

result = []
buf = []
prev_tax = None
for i in range(n + m):
    if not is_taxist[i]:
        buf.append(people[i])
        continue
    # taxist
    if prev_tax is None:
        result.append(len(buf))
    else:
        split_val = (people[i] - prev_tax) / 2 + prev_tax
        for i in range(len(buf)):
            if buf[i] <= split_val:
                result[-1] += 1
            else:
                result.append(len(buf) - i)
                break
        else:
            result.append(0)
    prev_tax = people[i]
    buf = []
result[-1] += len(buf)

print_answer(result)
