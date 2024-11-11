txt=input()
up=0
low=0
for i in txt:
    if(i.isupper()):
        up=up+1 
    else:
        low=low+1
if(low>up):
    ans = txt.lower()
if(low==up):
    ans = txt.lower()
else:
    ans = txt.upper()
print(ans)




