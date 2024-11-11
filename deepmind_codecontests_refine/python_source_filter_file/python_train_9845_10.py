a = int(input())
d = input()
s1 = 0
s2 = 0
for q in range(a):
    if(d[q] == "A"):
        s1 += 1
    if (d[q] == "D"):
        s2 += 1
if(s1>s2):
    print("Anton")
elif(s2>1):
    print("Danik")
else:
    print("Friendship")