s = input()
switch = {
    ">": "1000",
    "<": "1001",
    "+": "1010",
    "-": "1011",
    ".": "1100",
    ",": "1101",
    "[": "1110",
    "]": "1111",
}
ss = ""
for i in range(len(s)):
    ss += switch.get(s[i])
#print(ss)
ss = int(ss, 2)
print(ss % 1000003)

