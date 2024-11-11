s = input()
l = "a"
n = 1
for i in s:
    if i > l:
        l = i
        n = 1
    elif i == l:
        n+=1
print(l*n)
