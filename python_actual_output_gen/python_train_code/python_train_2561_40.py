
t = int(input())
for _ in range(t):
    s = input()
    start = s[0]
    end = s[-1]
    if len(s)>2:
        middle = s[1::2]
    else:
        middle = ""
    print (start+middle+end)