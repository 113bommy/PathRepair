stack = []
while True:
    try:
        n = int(input())
    except:
        break
    stack.append(n) if n else print(stack.pop())