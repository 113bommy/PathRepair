a=str(input(""))
if (any(x.isupper() for x in a) and any(x.islower() for x in a) 
    and any(x.isdigit() for x in a) and len(a) >= 5):
    
    print("CORRECT".lower().capitalize())
else:
    print(a.isupper())
    print("TOO WEAK".lower().capitalize())