# быстро жадно но криво
s=input()


for i in range(len(s)+1):
    for j in range(26):
        z=s[:i]+chr(ord('a')+j)+s[i:]
        if z==z[::-1]:
            print(z)
            exit(0)
print("NA")

            
