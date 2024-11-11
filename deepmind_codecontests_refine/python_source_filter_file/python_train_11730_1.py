_, k = map(int, input().split())
s = input()
dic = []
letters = "abcdefghijklmnopqrstuvwxyz"
for i in letters:
    dic.extend([ii for ii, v in enumerate(s) if v == ii])
foo = set(dic[:k])
print("".join(char for i, char in enumerate(s) if i not in foo))