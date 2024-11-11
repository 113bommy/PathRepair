l=['','-one','-two','-three','-four','-five','-six','-seven','-eight','-nine']
l1=['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen']
l2=['twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety']
l3=['zero','one','two','three','four','five','six','seven','eight','nine']

a=input()
if len(a)>1:
    print(l1[int(a[1])] if a[0]=='1' else l2[int(a[0])-2]+l[int(a[1])])
else:
    print(l3[int(a)])