s=input()
w="."
c=['a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y']
for i in s:
        
        if i not in c:
                if i.isupper():
                        w=w+i.lower()
                        w=w+'.'
                
                elif i.islower():
                        w=w+i
                        w=w+'.'



print(w[0:len(w)-2])

                 
