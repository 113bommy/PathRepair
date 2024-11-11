mates = 0
result = 0
while 1:
    try:
        inp = input()
        if inp.startswith('+'):
            mates += 1
        elif inp.endswith('-'):
            mates -= 1
        else:
            result += len(inp.split(':')[-1]) * mates
    except EOFError:
        break

print(result)