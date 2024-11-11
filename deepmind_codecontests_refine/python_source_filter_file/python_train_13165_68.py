#s = str(input())
#
#balance = 0
#sh = 0
#
#for i in s:
#    if i == "(": balance += 1
#    if i == ")": balance -= 1
#    if i == "#": sh += 1

#print(balance, sh)

s = str(input())

k1, k2 = 0, 0

if s[0] == "0": k1 = 2
if s[0] == "1": k1 = 5
if s[0] == "2": k1 = 2
if s[0] == "3": k1 = 3
if s[0] == "4": k1 = 3
if s[0] == "5": k1 = 4
if s[0] == "6": k1 = 2
if s[0] == "7": k1 = 5
if s[0] == "8": k1 = 1
if s[0] == "9": k1 = 2

if s[1] == "0": k2 = 2
if s[1] == "1": k2 = 5
if s[1] == "2": k2 = 2
if s[1] == "3": k2 = 3
if s[1] == "4": k2 = 3
if s[1] == "5": k2 = 4
if s[1] == "6": k2 = 2
if s[1] == "7": k2 = 5
if s[1] == "8": k2 = 1
if s[1] == "9": k2 = 2

print(k1 * k2)










