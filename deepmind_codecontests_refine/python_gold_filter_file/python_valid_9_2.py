
t = int(input())
s= []
for i in range(t):
    s.append(input(""))


for i in range(t):

    r= 0
    g =0
    freq = ["" for _ in range(200)]
    for j in range(len(s[i])):

        if "g" in freq[ord(s[i][j])]:
            if "r" in freq[ord(s[i][j])]:
                continue
            else:
                r += 1
                freq[ord(s[i][j])] += "r"

        elif "r" in freq[ord(s[i][j])] and "g" not in freq[ord(s[i][j])]:
            g+= 1
            freq[ord(s[i][j])] += "g"

        else:
            if r < g:
                r+= 1
                freq[ord(s[i][j])] += "r"
            else:
                g+= 1
                freq[ord(s[i][j])] += "g"


    print((r+g)//2)
    #print("r" in freq[ord(s[i][j])])

        