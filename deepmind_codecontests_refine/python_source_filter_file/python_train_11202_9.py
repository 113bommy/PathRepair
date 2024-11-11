s=input()
S=input()



d={}
for i in range(26):
    d[s[i]]=S[i]
    

  
#print (d['v'])    
a=input()

p=''

for i in range(len(a)):
    #print (a[i])
    if ord(a[i])>65 and ord(a[i])<91:
        p=p+str(d[a[i].lower()]).upper()
    elif ord(a[i])>97 and ord(a[i])<123:     
        p=p+str(d[a[i]])
    else:
        p=p+a[i]
        
print (p)   