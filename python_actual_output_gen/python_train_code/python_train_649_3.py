k = int(input())
HELLO_ELON_MUSK = []
for i in range(k):
    n = int(input())
    s = list(map(int, input().split()))
    X = sum(s)
    for j in range(len(s)-1):
        HELLO_ELON_MUSK.append((X-s[j], i, j))

flag = True
HELLO_ELON_MUSK.sort()
for i in range(len(HELLO_ELON_MUSK)-1):
    if (HELLO_ELON_MUSK[i][0] == HELLO_ELON_MUSK[i+1][0]) and (HELLO_ELON_MUSK[i][1] != HELLO_ELON_MUSK[i+1][1]):
        print('YES')
        print(HELLO_ELON_MUSK[i][1]+1, HELLO_ELON_MUSK[i][2]+1)
        print(HELLO_ELON_MUSK[i+1][1] + 1, HELLO_ELON_MUSK[i+1][2] + 1)
        flag = False
        break

if flag:
    print("NO")
