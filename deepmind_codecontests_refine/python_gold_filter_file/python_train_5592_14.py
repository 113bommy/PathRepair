n = input()
fl = n.find(".")

if n[fl-1] != "9":
    if int(n[fl+1]) < 5:
        print(n[:fl])
    elif int(n[fl+1]) >= 0.5:
        print(n[:fl-1]+str(int(n[fl-1])+1))
else:
    print("GOTO Vasilisa.")
