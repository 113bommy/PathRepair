holder=[]
x=input("")
holder=x.split(" ")
    
First= int(holder[0])*int(holder[1])+int(holder[3]*2)
Second=int(holder[0])*int(holder[2])+int(holder[4]*2)

if First==Second:
    print("Friendship")
elif First<Second:
    print("First")
else:
    print("Second")
