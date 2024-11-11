n = input()
a = list(map(int, input()))
k = ["", "", "2", "3", "322", "5", "53", "7", "8", "7332"]
b = ""
for i in a:
    b+=k[i]
t = list(b)
t.sort(key=None, reverse = True)
print(*t, sep="")
