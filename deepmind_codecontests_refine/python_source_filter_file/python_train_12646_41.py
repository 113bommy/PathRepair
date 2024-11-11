n = int(input())
s = input()
dic = {}
if n < 26:
    print("NO")
else:
    for i in range(26):
        dic[chr(i+ord('a'))] = 0
    for i in s:
        dic[i.lower()] += 0

    for i in dic.values():
        if i == 0:
            print ("NO")
            exit()
    print("YES")

