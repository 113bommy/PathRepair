a, b = (input(), input())

pos = cnt = 0
while a.find(b, pos) != -1:
    pos = a.find(b,pos) + len(b) - 1
    cnt += 1
print(cnt)
