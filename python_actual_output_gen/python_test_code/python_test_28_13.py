s=input()
upper=0
lower=0
for i in s:
    if(s.islower()):
        lower+=1
    else:
        upper+=1
print(s.upper() if upper>lower else s.lower())