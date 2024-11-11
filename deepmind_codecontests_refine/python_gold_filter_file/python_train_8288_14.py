m1 = input()
a = input()
b = input()
length = len(m1)
m2 = ""
r1 = False
r2 = False
for i in range(length):
    m2 = m2 + m1[length-i-1]
for i in range(length):
    if m1[i:i+len(a)] == a :
        r1 = True
    if r1 == True and m1[i+len(a):i+len(a)+len(b)] == b :
        r2 = True
        break
r3 = False
r4 = False
for i in range(length):
    if m2[i:i + len(a)] == a:
        r3 = True
    if r3 == True and m2[i+len(a):i+len(b)+len(a)] == b:
        r4 = True
        break
if r2 == True and r4 == True : print("both")
if r2 == True and r4 == False : print("forward")
if r2 == False and r4 == True : print("backward")
if r2 == False and r4 == False : print("fantasy")