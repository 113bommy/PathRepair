new_login = input()
n = int(input())
output = "Yes"
for i in range(n):
  iseqvivalent = True
  old_login = input()
  if(len(new_login) == len(old_login)):
    for j in range(len(new_login)):
      a = new_login[j].lower()
      b = old_login[j].lower()
      if(not (a == b or (a=="0" and b=="o") or (a=="o" and b=="0") or ((a=="1" or a=="l" or a=="i") and (b=="1" or b=="l" or b=="i")))):
        iseqvivalent = False
        break
    if(iseqvivalent):
      output = "No"
      
print(output)
        