from collections import deque
oleg = sorted(list(input()))
n = len(oleg)
oleg = deque(oleg[:(n-(n//2))])
igor = deque(sorted(list(input()),reverse = True)[:(n//2)])

result = ["" for i in range(n)]
result_front = 0
result_rear = -1
o = True
while result_front-result_rear-1 < n:
    if o:
        if len(igor) == 0 or oleg[0] < igor[0]:
            result[result_front] = oleg.popleft()
            result_front+=1
        else:
            result[result_rear] = oleg.pop()
            result_rear-=1
    else:
        if len(oleg) == 0 or igor[0] > oleg[0]:
            result[result_front] = igor.popleft()
            result_front+=1
        else:
            result[result_rear] = igor.pop()
            result_rear-=1
    #print(result)
    o = not o
print("".join(result))