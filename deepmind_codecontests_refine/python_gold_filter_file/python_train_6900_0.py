from sys import stdin,stdout
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

s = is1()
neg = False
intef = True
inte = ""
deci = ""
for i in s:
    if i == '-':
        neg = True
    elif i == ".":
        intef = False
    elif intef:
        inte += i
    else:
        deci += i
inte = str(int(inte))[::-1]
num =""
i = 0
while i < len(inte) - 3:
    num += inte[i: i + 3] + ','
    i += 3
num+=inte[i:]
num = num[::-1]
if len(deci):
    deci = deci[:2] + '0'*(2-len(deci))
else:
    deci = "00"
if neg:
    ans = f"(${num}.{deci})"
else:
    ans = f"${num}.{deci}"
print(ans)
    

    
    

