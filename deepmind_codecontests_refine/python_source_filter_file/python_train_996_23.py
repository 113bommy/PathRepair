# print ("Input a and b")
a,b = [int(x) for x in input().split()]

# print("Input c and d")
c,d = [int(x) for x in input().split()]

current = min(b,d)
if current == b:
    inc = a
    sub = d
    mod = c
else:
    inc = c
    sub = b
    mod = a

done = False
for i in range(100000):
    if (current > sub) and (current - sub) % mod == 0:
        firstanswer = current
        done = True
        break
    else:
        current += inc

if not done:
    firstanswer = float('inf')

current = max(b,d)
if current == b:
    inc = a
    sub = d
    mod = c
else:
    inc = c
    sub = b
    mod = a

done = False
for i in range(100000):
    if (current > sub) and (current - sub) % mod == 0:
        secondanswer = current
        done = True
        break
    else:
        current += inc

if not done:
    secondanswer = float('inf')

if firstanswer == float('inf') and secondanswer == float('inf'):
    print(-1)
else:
    print(min(firstanswer, secondanswer))



    
