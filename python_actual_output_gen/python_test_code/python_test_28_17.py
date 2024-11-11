s = input()
list = list(s)
upper = 0
lower = 0

for i in list:
    if (i.isupper()):
        upper += 1
    elif (i.islower()):
        lower += 1
    
if (upper>lower):
    s = s.upper()
elif (lower==upper):
    s = s.upper()
else:
    s = s.lower()

print(s)