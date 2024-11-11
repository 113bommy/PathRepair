s = input()
a = [0] * 26
b = [0] * 26
for i in s:
    a[ord(i) - ord('a')] += 1
    b[ord(i) - ord('a')] = 1

if sum(b) >= 4:
    print("Yes")
elif sum(b) >= 2:
    num = 0
    for i in range(26):
        if b[i] == 1 and a[i] >= 2:
            num += 1

    if sum(b) == 2 and num >= 2:
        print("Yes")
    elif sum(b) == 3 and num >= 1:
        print("Yes")
    else:
        print("No")
else:
    print("No")