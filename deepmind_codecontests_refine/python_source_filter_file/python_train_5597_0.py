import decimal
D=decimal.Decimal
s = input()
place = s.index(".")
last = s[place-1]
next = s[place+1]
#print(last,int(next)<5)

if last == "9" and int(next)>=5:
        print("GOTO Vasilisa.")
elif last=="9" and int(next)<5:
        #print("HI")
        print(s[:place])
elif last!="9" and int(next)>=5:
        #print("HO")
        print(s[:place-1]+str((int(s[place-1])+1)))
else:
        #print("NEATO")
        print(s[:place])



