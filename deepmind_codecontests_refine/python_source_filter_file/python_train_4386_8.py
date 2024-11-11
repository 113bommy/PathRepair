a = int(input())
b = str(input())
answer = ""
for x in range(a):
    if x == a - 1:
        answer = b[:2]
        break
    elif b[x] > b[x + 1]:
        answer = b[:x] + b[(x + 1):]
        break
print(answer)