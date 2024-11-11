m = int(input())
for i in range(m):
    d = input()
    trains = [d]
    for j in range(1, len(d)):
        trains.extend([d[:j][::-1] + d[j:], d[:j] + d[j:][::-1], d[:j][::-1] + d[j:][::-1], d[j:] + d[:j], d[j:][::-1] + d[:j], d[j:] + d[:j][::-1], d[j:][::-1] + d[:j][::-1]])
    print(len(set(trains)))