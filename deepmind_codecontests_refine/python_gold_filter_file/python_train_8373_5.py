str1 = input()
str2 = input()
def pos(ch):
    if 'A' <= ch <= 'Z':
        return ord(ch) - ord('A')
    return ord(ch) - 71

def countCharInString(str):
    countArray = [0] * 52
    for ch in str:
        if ch != " ":
            countArray[pos(ch)] += 1
    return countArray
a1 = countCharInString(str1)
a2 = countCharInString(str2)
flag = 'YES'
for i in range(52):
    if a2[i] > a1[i]:
        flag = 'NO'
print(flag)

