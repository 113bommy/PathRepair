n = int(input())
s = input()
k = int(input())
t = s[k-1]
for i in s:
    if i!=t:
        s = s.replace(i,"*")
print(s)