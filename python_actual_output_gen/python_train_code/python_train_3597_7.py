inp = input()
if inp[0] == 'a':
    if 2 < int(inp[1]) < 8:
        print(5)
        exit()
if int(inp[1]) == 8:
    if 'a' < inp[0] < 'h':
        print(5)
        exit()
if int(inp[1]) == 1:
    if 'a' < inp[0] < 'h':
        print(5)
        exit()
if inp[0] == 'h':
    if 2 < int(inp[1]) < 8:
        print(5)
        exit()
if 2 < int(inp[1]) < 7 and 'a' < inp[0] < 'h':
    print(8)
    exit()
print(3)