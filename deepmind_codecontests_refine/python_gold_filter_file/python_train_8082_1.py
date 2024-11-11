

a = input();
mas = input();
mas = mas.split(" ");
chet = 0;
nechet = 0;
temp = 0;
for i in range(0,int(a)):

    if (int(mas[i]) % 2 == 0):
        chet +=1;
    else:
        nechet +=1;




if(chet >= nechet):
    print(nechet)
elif(nechet > chet):
    temp = chet + int((nechet- chet)/3);
    print(temp);




