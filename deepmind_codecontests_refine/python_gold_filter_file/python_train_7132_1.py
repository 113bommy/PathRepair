IMPOSSIBLE = "Impossible"

scopes = {
    "{": "}",
    "(": ")",
    "[": "]",
    "<": ">"
}

stack = []
swap = 0
for i in input():
    if i in scopes:
        stack.append(i)
    elif stack:
        if scopes[stack[-1]] != i:
            swap += 1
        stack.pop()
    else:
        print(IMPOSSIBLE)
        break
else:
    print(swap if not stack else IMPOSSIBLE)