n,answer=map(int, input().split())
sad = 0

for i in range(n):
    type, amount = input().split(' ')
    if type == '+':
        answer += int(amount)
    else:        
        if int(amount) >= answer:
            sad += 1
        else:
            answer -= int(amount)
print(answer, sad)        