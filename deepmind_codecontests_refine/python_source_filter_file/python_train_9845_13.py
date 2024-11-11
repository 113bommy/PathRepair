
n=map(int,input().split())

a=input().strip()

anton,danik=0,0

for letter in a:
    if letter=='A':
        anton+=1
    else:
        danik+=1
        
if anton==danik:
    print ('Friendship')
elif anton>danik:
    print ('ANTON')
else:
    print ('DANIK')



