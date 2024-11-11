a = ["a","e","i","o","u","2","4","6","8","0"]
b = list(input()); ans = 0
for i in range(len(b)):
    if b[i] in a: ans += 1
print(ans)