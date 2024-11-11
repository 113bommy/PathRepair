s = input()
arr = list(s)
s = 97
for i in range(len(arr)):
    x = ord(arr[i])
    if x<=s:
        arr[i] = chr(s)
        s+=1
        if s==123:
            break
if s==123:
    print(''.join(arr))
else:
    print(-1)
# print(s)