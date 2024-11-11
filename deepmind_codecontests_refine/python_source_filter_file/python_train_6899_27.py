
s=input()
L=[]
R=[]
n=len(s)
print(4)
s1=s[:]
s=s[1:n-1][::-1]+s
print("L",n-2)

s=s+s[n-1:-1][::-1]
print("R",n)

s=s+s[n-2:-1][::-1]

print("R",n-1)
s=s+s[(-(n-1)):-1][::-1]

print("R",4*n-5)
