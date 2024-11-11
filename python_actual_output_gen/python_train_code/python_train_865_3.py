FirstDay=input()
SecondDay=input()
ListOfDays=["monday","tuesday","wednesday","thursday","friday","saturday","sunday"]

if FirstDay in ListOfDays:
    a=ListOfDays.index(str(FirstDay))
    if a > 7 :
        a = a%7
if SecondDay in ListOfDays:
    b=ListOfDays.index(str(SecondDay))
    if b > 7 :
        b = b%7
o=[a,a+2,a+3]
if b in o:
    print("YES")
else:
    print("NO")
