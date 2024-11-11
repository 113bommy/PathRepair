n = int(input())
a = int(input())
b = int(input())
c = int(input())

distance = 0
Pos = 'R'
for i in range(n-1):
    if Pos == 'R':
        if a<b:
            distance+=a
            Pos = 'O'
        else:
            distance+=b
            Pos = 'E'
    if Pos == 'E':
        if b<c:
            distance+=b
            Pos = 'R'
        else:
            distance+=c
            Pos = 'O'
    if Pos == 'O':
        if a<c:
            distance+=a
            Pos = 'R'
        else:
            distance+=c
            Pos = 'E'

print(distance)
