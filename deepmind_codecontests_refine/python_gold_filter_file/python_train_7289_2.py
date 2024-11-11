s = input()
q = int(input())
for i in range(q):
    command = input().split()
    a, b = int(command[1]), int(command[2]) + 1
    if command[0] == "print":
        print(s[a:b])
    elif command[0] == "reverse":
        s = s[:a] + s[a:b][::-1] + s[b:]
    elif command[0] == "replace":
        s = s[:a] + command[3] + s[b:]