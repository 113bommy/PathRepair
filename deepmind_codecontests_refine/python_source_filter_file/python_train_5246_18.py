a= int(input())
b= input()
if 'R' not in b:
    c = len(b) - b[::-1].index('L')
    d = b.index('L') + 1
elif 'L' not in b:
    c = b.index('R') + 1
    d = len(b) -  b[::-1].index('R')
else: 
    c = b.index("R")+1
    d = b.index('L') 
print(c , d)
