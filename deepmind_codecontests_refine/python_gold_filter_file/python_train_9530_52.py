
string="NO"
n=int(input())
for i in range (n) :
    a, b, c = input().split()
    if int (c)>int (b) and int (b) >= 2400:
        string="YES"
    i+=1
print(string)