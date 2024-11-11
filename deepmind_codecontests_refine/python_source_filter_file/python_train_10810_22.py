s = list(input())
s = s[:-1]

while len(s)%2!=0 or s[:len(s)//2]!=s[len(s)//2:][::-1]:
    s = s[:-1]
print(len(s))