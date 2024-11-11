# быстро жадно но криво
s=input()


for i in range(len(s)):
    for j in range(26):
        z=s[:i]+chr(ord('a')+j)+s[i:]
        if z==z[::-1]:
            print(z)
            halt()
print("NA")
            
