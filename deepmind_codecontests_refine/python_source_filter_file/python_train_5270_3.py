s = input()
n = len(s)
a = ['a','e','i','o','u']
c = 0
d = 0
for i in range(n):
    if s[i] not in a:
        if c==0:
            print(s[i],end="")
            c+=1
            d = 1
        elif c==1:
            if s[i]==s[i-1]:
                print(s[i],end="")
            else:
                d+=1
                print(s[i],end="")
            c+=1
        else:
            if s[i]!=s[i-1]:
                d+=1
            if d>1:
                print(" ",end="")
                print(s[i],end="")
                d = 0
                c = 0
            else:
                print(s[i],end="")


    else:
        print(s[i],end="")
        c = 0
        d = 0
print()