line = input()
for _ in range(int(input())):
    x = input().split()
    order = x[0]
    a = int(x[1])
    b = int(x[2])+1
    if order == "print":
        print(line[a:b])
    elif order == "reverse":
        line = line[:a] + line[a:b][::-1] + line[b:]
    elif order == "replace":
        line = line[:a] + x[3] + line[b:]

