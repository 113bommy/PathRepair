napis = input().split()
ileRzedow = int(napis[0])
jakaSuma = int(napis[1])
for x in range(ileRzedow):
    nowyNapis = '0' * x + '{0}'.format(jakaSuma) + '0' * ((ileRzedow - 1) - x)
    print(nowyNapis)
