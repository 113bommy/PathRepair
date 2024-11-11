string = input()
good = list(string)
s = input()
a = len(s)
condition = "*" in s
n = int(input())
results = []
for x in range(n):
    temp = s
    t = input()
    b = len(t)
    condition1 = a == b - 1 and not condition
    if a > b + 1 or condition1:
        result = "NO"
    elif b > a and not condition:
        result = "NO"
    else:
        result = "YES"
        if condition:
            p = s.index("*")
            q = a - p
            if q == 1:
                r = t[p:]
            else:
                r = t[p:-q + 1]
            for x in r:
                if x in good:
                    result = "NO"
                    break
            temp = s[:p] + r + s[p + 1:]
        if result == "YES":
            for x in range(b):
                if temp[x] == "?":
                    if not t[x] in good:
                        result = "NO"
                        break
                elif temp[x] != t[x]:
                    result = "NO"
                    break
    results.append(result)
for x in results:
    print(x)