n = int(input())
arr = input()
room = ['0' for _ in range(10)]
for i in range(n):
    if arr[i] == 'L':
        for j in range(10):
            if room[j] == '0':
                room[j] = 'L'
                break
    elif arr[i] == 'R':
        j = 9
        while j >= 0:
            if room[j] == '0':
                room[j] = 'R'
                break
            j-=1
    else:
        room[ord(arr[i]) - 48] = '0'
for i in range(10):
    if room[i] == 'L' or room[i] == 'R':
        print('1', end = '')
    else:
        print('0', end = '')