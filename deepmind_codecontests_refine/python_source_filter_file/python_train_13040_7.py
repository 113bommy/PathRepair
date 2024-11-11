inp = int(input())
for num in range(inp):
    counter = 0
    inp0 = int(input())
    inp1 = list(map(int, input().split()))
    inp2 = list(map(int, input().split()))

    min_inp1 = min(inp1)
    min_inp2 = min(inp2)

    index1 = inp1.index(min_inp1)
    index2 = inp2.index(min_inp2)

    counter += abs(inp1[index2] - min_inp1)
    counter += abs(inp2[index1] - min_inp2)
    for x in range(inp0):
        if x == index2 or x == index1:
            continue
        else:
            if inp1[x] - min_inp1 > inp2[x] - min_inp2:
                counter += (inp1[x] - min_inp1)
            else:
                counter += (inp2[x] - min_inp2)
print(counter)