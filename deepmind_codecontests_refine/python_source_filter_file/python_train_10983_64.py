word = input()
l = len(word)

count = 0
for i in range(0,l):
    if(word[i]>='A' and word[i]<='Z'):
        count+=1


if((l%2==0 and count>(l/2)) or (l%2==1 and count>=(l/2)+1)):
    print (word.upper())
else:
    print (word.lower())
