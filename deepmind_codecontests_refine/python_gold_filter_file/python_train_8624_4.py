n = int(input())
s = input()
s += s[:2]

for ans in ["SS", "SW", "WW", "WS"]:
    for i in range(1,n+1):
        if (ans[-1] == "S" and s[i] == "o") or (ans[-1] == "W" and s[i] == "x"):
            ans += ans[-2]
        else:
            ans += ("S" if ans[-2] == "W" else "W")
        

    if ans[:2] == ans[n:]:
        print(ans[:n])
        exit()

print(-1)