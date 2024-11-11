string = input()
n = int(input())
for i in range(n):
    inp = [x for x in input().split()]
    a = int(inp[1])
    b = int(inp[2])
    if inp[0] == 'print':
        print(string[a:b+1])
    elif inp[0] == 'reverse':
        string = string[:a] + string[a:b+1][::-1] +string[b+1:]
    else:
        string = string[:a] + inp[3] + string[b+1:]

