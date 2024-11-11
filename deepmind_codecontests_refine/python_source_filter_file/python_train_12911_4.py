a = "abcdefghijklmnopqrstuvwxyz"
while 1:
    try:
        b += input().lower()
    except:
        break
for i in range(26):
    print(a[i],':',b.count(a[i]))
