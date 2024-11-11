
n, k = map(int, input().split())
digit = list(map(str, input()))

for index, value in enumerate(digit):
    if k == 0: break
    else:
        if len(digit) == 1:
            if value != "1":
                digit[index] = "0"
                k -= 1
        else:
            if index == 0 and value != "1":
                digit[index] = "1"
                k -= 1
            elif index > 0 and value != "0":
                digit[index] = "0"
                k -= 1
        
print("".join(digit))