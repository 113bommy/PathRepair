s = input()
arr = []
firstZero = 1
sets = 0
if s.count("0") > 0:
    for i in range(0, len(s)):
        arr.append(s[i:i+1])
        if firstZero > 0 and s[i:i+1] == "0":
            sets = i
            firstZero-=1
    arr.pop(sets)
else:
    for i in range(0, len(s)):
        arr.append(s[i:i+1])
    arr.pop(0)
print(arr)