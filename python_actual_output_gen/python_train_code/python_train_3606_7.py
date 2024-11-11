n,a,b,c,d = map(int,input().split())
s = input()

ans = "No"
if "##" in s[a-1:c] or "##" in s[b-1:d]: pass
else:
    if c<d: ans = "Yes"
    else:
        if "..." in s[b-2:d]: ans = "Yes"


print(ans)
