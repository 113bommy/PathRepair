# Codeforces 534 Div 2 - Problem B

n = str(input())

Stack = ['a', 'b']

res = 0
for i in range(0, len(n)):
    if len(Stack) == 0:
        Stack.append(n[i])
    elif n[i] == Stack[len(Stack) - 1]:
        Stack.pop()
        res = 1 - res
    else:
        Stack.append(n[i])

if res == 0:
    print("No")
else:
    print("Yes")