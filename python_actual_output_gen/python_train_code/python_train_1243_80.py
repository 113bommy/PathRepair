n,x = map(int,input().split())
d = 0

for _ in range(n):
    s = input()
    s1,s2 = ("","")

    if(s[0] == '+'):
        for i in range(2,len(s)):
            s1 += s[i]
        
        x += int(s1)
    else:
        for j in range(2,len(s)):
            s2 += s[j]

        if(x > int(s2)):
            x -= int(s2)
        else:
            d += 1
        
print(x,d)