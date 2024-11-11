n = int(input())
s = input()
c = s.count(".")
ans = c
for i in range(n):
    if s[i] =="#":
        c +=1
    else:
        c -=1
    ans = min(ans,m)
print(ans)