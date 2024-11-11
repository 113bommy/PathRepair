n=int(input())
origin=input()
code=input()
move=0
for i in range(n):
    d=abs(int(origin[i])-int(code[i]))
    move+=min(d,10-d)
print(move)
