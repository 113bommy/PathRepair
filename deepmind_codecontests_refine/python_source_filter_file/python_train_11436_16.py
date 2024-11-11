n=int(input())
S=input()
l=0
r=0
for s in S :
    if s == ")" :
        if r :
            r -= 1
        else :
            l += 1
    else :
        r += 1
ans = "("*l + S + ")"
print(ans)
