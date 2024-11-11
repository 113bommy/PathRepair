n = int(input())
s = input()
s2 = input()
ans = 0
i = 0
while i < n:
    if s[i] != s2[i]:
        if i+1 < n and s[i+1] != s2[i+1] and s[i] == s[i+1]:
            ans += 1
            i += 2
        else:
            ans += 1
            i += 1
    else:
        i += 1
print(ans)
    
