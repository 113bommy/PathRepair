a = input()
b = input()
m = int(input())
for i in range(m):
    ans = "YES"
    n = input()
    w = b
    if "*" in w:
        if len(w) <= len(n):
            w = w.replace("*", "*" * (abs(len(w) - len(n)) + 1))
        elif len(w) == len(n) + 1:
            w = w.replace("*", "")
    if len(n) != len(w):
        ans = "NO"
    else:
        for i in range(len(n)):
            if w[i] == "*":
                if n[i] in a:
                    ans = "NO"
                    break
            elif w[i] == "?":
                if n[i] not in a:
                    ans = "NO"
                    break
            else:
                if w[i] != n[i]:
                    ans = "NO"
                    break
        else:
            ans = "YES"
    print(ans)