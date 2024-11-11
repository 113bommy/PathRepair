n,k = map(int,input().split())
s = input()

a = ""
i = 0
o = 0
while i < len(s)  and o < k:
    if i == 0:
        if (s[i] != "1"):
            a+="1"
            o+=1
        else:
            a+="1"



    elif s[i] != "0":
         a += "0"
         o+=1
    else:
        a+=s[i]

    i += 1


for i in range(i,len(s)):
    a+=s[i]

if len(s) != 1:
    print(a)
else:
    if (s=="1"):
        print(0)
    else:
        print(1)
