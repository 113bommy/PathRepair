n = int(input())
a = input()
l = 0
mem = {'1111': '4', '11': '2', '1111111': '7', '111111111': '9', '11111111': '8', '111': '3', '111111': '6', '1': '1', '11111': '5', '': '0'}
ans = ''
i = 0
l = 0
while i < n:
    while a[i] != '0':
        i += 1
        if i >= n:
            break  
    ans += mem[a[l:i]]
    i += 1
    l = i  
    if i == n:
        if a[i-1] == '0':
            ans += '0'
print(ans)