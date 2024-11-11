reps = int(input())

for _ in range(reps):
    n, k = list(map(int, input().split()))
    taps = list(map(int, input().split()))
    dtaps = [taps[0]]
    for i in range(1, len(taps)):
        dtaps.append(int(((taps[i] - taps[i-1])/2)+0.5))
    dtaps.append(n-taps[-1]+1)
    print(max(dtaps))
