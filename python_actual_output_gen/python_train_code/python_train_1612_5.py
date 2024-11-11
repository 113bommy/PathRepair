a = input("")
outstring = ""
check1 = True
if a[0] == "9":
    outstring = outstring + "9"
    check1 = False
for value in range(len(a)):
    if value == 0 and check1 == True:
        if int(a[value])<5:
            outstring = outstring + a[value]
        else:
            outstring = outstring + str(9-int(a[value]))
    if value != 0:
        if int(value)<5:
            outstring = outstring + a[value]
        else:
            outstring = outstring + str((9-int(a[value])))
print(outstring)
