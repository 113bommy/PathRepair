username = input("")
letters = []
counter = 0
for char in username:
       if char not in letters:
              counter +=1
       letters.append(char)
if counter%2 == 0:
       print("CHAT WITH HIM")
else:
       print("IGNORE HIM")