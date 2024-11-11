n , k = map(int , input().split())
s = input()
b = input()
i = 0
ans = 0
while i < len(s) :
    if s[i] in b:
        c = 0
        for j in range(i , n):
            if s[j] in b:
                c += 1
                i = j + 1
            else:
                break
        ans+=(c * (c + 1)) // 2
    else:
        i += 1
print(ans)

