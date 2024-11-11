s=int(input())
steps=0
for i in range(5,0,-1):
    steps+=s//i
    s%=i
print(s)
    