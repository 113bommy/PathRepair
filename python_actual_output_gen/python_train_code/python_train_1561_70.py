s=input()
s=s.lower()
ans=""
for i in s:
    if i not in"aeiou":
        ans+="."+i
print(ans)
    