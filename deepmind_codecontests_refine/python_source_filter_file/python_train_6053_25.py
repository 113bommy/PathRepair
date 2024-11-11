'''
t= input()
lng= len(t)
li1=[]; li2=[]
for i in range(lng):
    if t[i]!='a':
        li1.append(t[i])
    elif t[i]=='a':
        li2.append(i)
        
aa= ''.join(li1)
if len(aa)==0:
    print(t); exit(0)
if len(aa)%2==1:
    print(':('); exit(0)
if len(aa)%2==0:
    #print(123)
    l= int(len(aa)/2); lp= l#; print(l)
    ll= aa[l:]; lll=aa[0:l] #; print(ll)
    if ll!=lll:
        print(':('); exit(0)
    if ll not in t:
        print(':('); exit(0)
    tp= t[::-1]; tc= ll[::-1]#; print(tp,tc)
    if tp.find(tc)!=0:
        print(':('); exit(0)
    if tp.find(tc)==0:
        ul= len(tc)
        lu= tp[ul:][::-1]
        print(lu); exit(0)
        
   '''

a= int(input()); b= int(input()); c= int(input()); d= int(input()); sv=0; vs=0
if a+b+c==b+c+d:
    sv=1
if sv==1:
    if a+b+d<1 and c>0:
        sv=0
print(sv)

        














        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        