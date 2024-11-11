import string

s = str(input())

answer = ""

for i in range(max(1, len(s) - 26)):
    temp = set()
    count = 0
    current_s = list(s[i:i + 26])
    for element in current_s:
        if element == "?":
            count += 1
        else:
            temp.add(element)

    if len(temp) + count == 26:
        for j in range(26):
            if current_s[j] == "?":
                for element in list(string.ascii_uppercase):
                    if element not in temp:
                        temp.add(element)
                        current_s[j] = element
                        break

        answer += s[:i].replace("?", "A") + "".join(map(str, current_s)) + s[i + 26:].replace("?", "A")
        break

if answer != "":
    print(answer)
else:
    print(-1)