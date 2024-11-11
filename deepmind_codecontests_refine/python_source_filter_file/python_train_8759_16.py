from string import ascii_uppercase
n=int(input())
s=input()
m=10**5
A=ord('A')
C=ord('C')
T=ord('T')
G=ord('G')
Z=ord('Z')
for i in range(n-3):
    x=0
    x+=min(ord(s[i])-A,Z-ord(s[i])+1,ord(s[i])-A+Z-A)
    
    x+=min(abs(ord(s[i+1])-C),Z-ord(s[i+1])+C-A+1,ord(s[i+1])-A+Z-C)
    
    x+=min(abs(ord(s[i+2])-T), Z-ord(s[i+2])+T-A+1, ord(s[i+2])-A+Z-T)
    x+=min(abs(ord(s[i+3])-G),Z-ord(s[i+3])+G-A+1, ord(s[i+3])-A+Z-G)
    m=min(m,x)


print(m)