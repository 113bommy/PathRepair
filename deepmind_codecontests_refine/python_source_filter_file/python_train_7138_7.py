n = int(input())
x = 0
con3 = "YES"
for i in range(0,n):
    s = input()
    s = s.split()
    s[0] = int(s[0])
    if ((s[0] < 0 or s[0] > 20000) and (s[1] == "North" or s[1] == "South")):
        con3 = "NO"
    if s[1] == "North":
        x -= s[0]
    elif s[1] == "South":
        x += s[0]
    if x < 0 or x > 20001 :
        con3 = "NO"
    if ((x == 0 or x == 20000) and (s[1] == "West" or s[1] == "East")):
        con3 = "NO"
if x != 0:
    con3 = "NO"
print(con3)