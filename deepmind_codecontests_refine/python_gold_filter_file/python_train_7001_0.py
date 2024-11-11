base = "abacaba"

t = int(input())

for case in range(t):
    n = int(input())
    s = input()
    cnt = 0
    for i in range(n):
        if s[i:i+7] == base:
            cnt += 1

    if cnt == 1:
        print("Yes")
        ans = s.replace("?", "d")
        print(ans)

    elif cnt >= 2:
        print("No")

    else:
        ans = ""
        for i in range(n - 6):
            bl = True
            for e1, e2 in zip(s[i:i+7], base):
                if e1 == "?":
                    continue
                if e1 != e2:
                    bl = False

            if bl:
                cand = s[:i].replace("?", "d") + base + s[i+7:].replace("?", "d")
                cnt = 0
                for j in range(n):
                    if cand[j:j + 7] == base:
                        cnt += 1

                if cnt == 1:
                    ans = cand
                    break

        if ans:
            print("Yes")
            print(ans)
        else:
            print("No")
