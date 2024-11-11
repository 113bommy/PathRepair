n, s = int(input()), input()
k = ['a']
ans = ''
maxColor = 1
for symb in s:
    for i in range(len(k)):
        if symb >= k[i]:
            ans += str(i + 1) + ' '
            if i + 1 > maxColor:
                maxColor = i + 1
                k.append('a')
            k[i] = symb
            break
print(maxColor)
print(ans)