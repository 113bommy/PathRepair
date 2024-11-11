t = int(input())


def pre_flip(string, pre_length):
    new_string = ""
    for x in range(pre_length):
        if string[x] == "0":
            new_string += "1"
        else:
            new_string += "0"
    return new_string[::-1] + string[pre_length:]


for x in range(t):
    a = int(input())
    b = str(input())
    c = str(input())
    answer = [0]
    x = 1
    while x <= a and b != c:
        if b[-x] != c[-x]:
            if b[x - 1] == c[-x]:
                b = pre_flip(b, x)
                answer.append(x)
            b = pre_flip(b, (a+1) - x)
            answer.append((a+1) - x)
        x += 1

    answer[0] = len(answer) - 1
    for x in answer:
        print(x,end=" ", flush=True)
    print("\n")