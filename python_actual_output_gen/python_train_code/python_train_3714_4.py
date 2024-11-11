s = input()
k = int(input())

ans = ''

for i in range(len(s)-1):
    a = 123-ord(s[i])
    if a==26:
        ans += s[i]
    elif a<k:
        ans += 'a'
        k-=a
    else:
        ans += s[i]

ans += chr((ord(s[-1])-97+k)%26+97)

print(ans)