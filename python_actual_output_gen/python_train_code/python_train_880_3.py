
N = int(input())

number = list(map(int, list(input())))

f = list(map(int, input().split()))


for i in range(N):
    if f[number[i]-1] > number[i]:
        while i < N and f[number[i]-1] > number[i]:
            number[i] = f[number[i]-1]
            i += 1

        break

print(''.join(map(str, number)))


# print("%d, %d" % (N, M))