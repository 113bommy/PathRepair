W = input().lower()
ans = 0
while 1:
    T = input()
    if T == "END_OF_TEXT":
        break
    ans += T.lower().count(W)
print(ans)
