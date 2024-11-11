s = input()
count1 = 0 
count2 = 0

for i in range(len(s)):
    if(s[i]=='4'):
        count1+=1
    elif(s[i]=='7'):
        count2+=1

if(count1==count2):
    print("-1")
elif(count1==count2):
    print("4")
elif(count1>count2):
    print("4")
else:
    print("7")
