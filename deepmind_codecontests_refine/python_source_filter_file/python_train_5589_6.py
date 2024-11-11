n = str(input())
f = n.index("."); b = ""
if n[f-1] == "9": print("GOTO Vasilisa")
else:
    for i in range(len(n)):
        if n[i] != ".": b += n[i]
        else: break
    if int(n[f+1]) >= 5: print(int(b)+1)
    else: print(int(b))