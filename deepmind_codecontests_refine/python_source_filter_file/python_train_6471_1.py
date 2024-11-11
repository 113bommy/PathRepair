k = int(input())
if k <= 9:
    print(k)
else:
    length = len(str(k))
    s = ""
    num = 0

    for i in range(length - 2):
        num += (9*(10**i))*(i + 1)
        temp = num + (9*(10**(i + 1)))*(i + 2)
        if temp > k:
            length = i + 2
            break

    for i in range(length - 1):
        s = s + "1"
    #print(s)

    previous_value = 9 * int(s)
    try_value = k - num
    #print(try_value)
    #print(previous_value)
    #print(length)
    if try_value % length == 0:
        div_value = try_value // length
        temp_string = str(previous_value + div_value)
        print(temp_string[len(temp_string) - 1])
    else:
        div_value = (try_value // length) + 1
        temp_string = str(previous_value + div_value)
        differ = (div_value * length) - try_value
        print(temp_string[len(temp_string) - differ - 1])
