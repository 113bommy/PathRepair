n = int(input())
TC = list(map(int, input().split()))
new = []

for i in range(n):
    for T in TC:
        if T * 2 in TC or (T%3 ==0 and T//3 in TC):
            continue
        else:
            new.append(T)
            TC.remove(T)

print(new[::-1])