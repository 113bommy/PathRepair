class dicegames:
    def __init__(self, m, c):
        self.m = m
        self.c = c


n = int(input())
arr = []
for i in range(n):
    m, c = map(int, input().split())
    arr.append(dicegames(m, c))

miskha = 0
chris = 0
ans = 0
for i in range(n):
    if arr[i].m > arr[i].c:
        miskha += 1
    elif arr[i].m < arr[i].c:
        chris += 1
    else:
        miskha == miskha
        chris == chris
if miskha > chris:
    print('Mishka')
elif miskha < chris:
    print('Chris')
else:
    print('Friendship is magic!^^')
