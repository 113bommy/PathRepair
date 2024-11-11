t = int(input())
numb = list(map(int, input().split()))
chet = 0
nechet = 0
for i in range(t):
    if numb[i] % 2 == 0:
        chet += 1
        last_chet = i
    else:
        nechet += 1
        last_nechet = i
    if chet != 0 and nechet != 0 and abs(chet - nechet) > 1:
        if chet > nechet:
            print(last_nechet + 1)
        else:
            print(last_chet + 1)
        break