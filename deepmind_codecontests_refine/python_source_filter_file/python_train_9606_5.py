t = int(input())
powers = [2 ** i for i in range(30)]
for i in range(t):
    n = int(input())
    counts = [0]*30
    a = map(int, input().split())
    for x in a:
        for j in range(1,30):
            if x < powers[j]:
                counts[j-1] += 1
                break
    total = 0
    for count in counts:
        total += (count * (count-1))//2
    print(total)
