t = '<3' + '<3'.join(input() for i in range(int(input()))) + '<3'
p=input()
s="yes"
j=0
for c in t:
    j = p.find(c, j)+1
    if j == 0:
        s = 'no'
        break
print(s)