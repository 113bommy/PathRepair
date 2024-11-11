t = int(input())

for tc in range(t):

    n = int(input())
    s = input()

    blocks = {}
    blocks[0] = [1, s[0]]

    p = s[0]

    curr = 0
    for i in range(1, n):
        if s[i] == p:
            blocks[curr][0] += 1
        else:
            curr += 1
            p = s[i]
            blocks[curr] = [1, p]

    arr = []
    for i in range(len(blocks)):
        arr.append(blocks[i])

    if len(arr) == 1:
        print((arr[0][0]-4)//3 + 2)
        continue

    if arr[0][1] == arr[-1][1]:
        arr[0][0] += arr[-1][0]

    del arr[-1]

    cnt = 0
    for i in arr:
        cnt += i[0]//3

    print(cnt)


