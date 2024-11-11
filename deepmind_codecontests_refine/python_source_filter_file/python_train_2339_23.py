f = input()
m = input()
s = input()

cases = dict()

cases["scissors"] = "";
cases["rock"] = "";
cases["paper"] = "";

for key in cases:
    if key == f:
        cases[key] += "F"
    if key == m:
        cases[key] += "M"
    if key == s:
        cases[key] += "S"

sum = 0
for k, v in cases.items():
    if len(v) == 1:
       sum += 1
       if sum == 3:
           print("?")
    elif len(v) == 2:
        if (k == "rock" and len(cases["scissors"]) == 1) or(k == "scissors" and len(cases["paper"]) == 1) or (k == "paper" and len(cases["rock"]) == 1):
            print("??")
            break
        elif k == "rock" and len(cases["paper"]) == 1:
            print(cases["paper"])
            break
        elif k == "paper" and len(cases["scissors"]) == 1:   
            print(cases["scissors"])
            break
        elif k == "scissors" and len(cases["rock"]) == 1:
            print(cases["rock"])
            break     
    elif len(v) == 3:
        print("?")
        break


        

        
