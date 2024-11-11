c,*s=input()
n=len(s)
for b in range(1<<n):
    t = c + ""
    for i in range(n):
        t += ["-","+"][b>>i & 1] + s[i]
    if eval(t) == 7:
        print(t+"=7")
        exit()