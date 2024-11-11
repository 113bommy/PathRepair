current = str(input())


nexti = ""
current = current[::-1]

carry = False;

for n in current[:len(current)-1]:
    if carry:
        nexti += str(10 - int(n) - 1)
    else:
        if int(n) == 0:
            nexti += str(0)
        else:
            nexti += str(10-int(n))
            carry = True
if not(carry):
    nexti+=str(1)
nexti = nexti[::-1]
print(nexti)