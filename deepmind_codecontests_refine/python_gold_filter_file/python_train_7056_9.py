S = input()
Q = int(input())
flip = False
head = ''
tail = ''
for _ in range(Q):
    q = input()
    if q == '1':
        flip = not flip
        head, tail = tail, head
    else:
        _, f, c = q.split()
        if f == '1':
            head += c
        else:
            tail += c
if flip:
    S = S[::-1]
print(head[::-1] + S + tail)
