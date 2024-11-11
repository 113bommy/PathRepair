n = int(input())
s = input()
string = ""
scnt = 0
scntleft = s.count("(")
scntright = s.count(")")
em = 0

if n%2 == 1:
    em = 1
elif scntleft > n/2 or scntright > n/2:
    em = 1
else:
    for i in range(n):
        if s[i] == "(":
            string += s[i]
            scnt += 1
        elif s[i] == ")":
            string += s[i]
            scnt -= 1
            if scnt == 0 and i < (n-1):
                em = 1
                break
        elif s[i] == "?":
            if scntleft < n/2 :
                string += "("
                scnt += 1
                scntleft += 1
            else:
                string += ")"
                scnt -= 1
                scntright += 1
                if scnt == 0 and i < (n-1):
                    em = 1
                    break
if em == 1 or scnt > 0:
    print (":(")
else:
    print (string)
