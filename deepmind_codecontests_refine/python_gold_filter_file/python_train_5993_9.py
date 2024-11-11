a=[int(i) for i in (str(input())).split() ]
#print(a)
a=str(input())
a=a.replace('(',' ( ')
a=a.replace(')',' ) ')
a=a.replace('_',' ')

a=a.split();
maxword=0
wordsin=0
curthing=0
for i in a:
    if i=='(':
        curthing+=1
        continue
    if i==')':
        curthing-=1
        continue
    #print("%s %s"%(i,curthing))

    if curthing>0:
        wordsin+=1
    else:
        maxword=max(maxword,len(i))
        
print("%s %s"%(maxword,wordsin))
    
