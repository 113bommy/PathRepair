a,b,c = input().split(' ')
a,b,c = int(a),int(b),int(c)
input()
safes = range(b+1,c)
line3 = input().split(' ')
c = 0
for sf in line3:
    if int(sf) in safes: c+= 1
print(c)