ins = map(int, input().split())
_, packet_n = next(ins), next(ins)

pepples = map(int, input().split())

tot = 0
for p in pepples:
    tot += p // packet_n
    if p % packet_n != 0:
        tot += 1
if tot % 2 == 0:
    print(tot)
else:
    print(tot // 2 + 1)