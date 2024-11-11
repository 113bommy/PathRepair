
s = input()
n = int(input())

cont = 0
for i in s:
    if i.isalpha():
        cont+=1

r = ''
if cont>n:
    for i in range(len(s)-1):
        if (s[i+1]=='?' or s[i+1]=='*') and cont>n:
            cont-=1
        else:
            if s[i].isalpha():
                r += s[i]
    if s[len(s)-1].isalpha():
        r+=s[len(s)-1]
elif cont<n:
    # print(n-cont)
    for i in range(len(s)-1):
        if s[i+1]=='*' and cont<n:
            r += (n-cont+1)*s[i]
            cont += n-cont
        else:
            if s[i].isalpha():
                r += s[i]
    if s[len(s)-1].isalpha():
        r+=s[len(s)-1]
else:
    for i in s:
        if i.isalpha():
            r+=i
# print(r, len(r))
if len(r)!=n:
    print("Impossible")
else:
    print(r)
