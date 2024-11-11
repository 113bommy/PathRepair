input()
seq = input()
if len(seq) % 2:
    part1 = seq[:len(seq)//2+1]
    part2 = seq[len(seq)//2+1:]
    ans = "".join(list(map(lambda x: "".join(x), zip(part1[::-1], part2)))) + seq[0]
else:
    part1 = seq[:len(seq)//2]
    part2 = seq[len(seq)//2:]
    ans = "".join(list(map(lambda x: "".join(x), zip(part1[::-1], part2))))

print(ans)