k = int(input())

if(k>0 and k<10):
    print(k)
elif(k>=10 and k<190):
    result = 10+int((k-10)/2)
    if(k-10)%2 == 0:
        print(int(result/10))
    else:
        print(result%10)
elif (k>=190 and k<2890):
    result = 100+int((k-190)/3)
    if(k-190)%3 == 0:
        print(int(result/100))
    elif(k-190)%3 == 1:
        print(int((result%100)/10))
    else:
        print(result%10)
else:
    result = 1000+int((k-2890)/4)
    if(k-2890)%4 == 0:
        print(int(result/1000))
    elif(k-2890)%4 == 1:
        print(int((result%1000)/100))
    elif(k-2890)%4 == 2:
        print(int((result%100)/10))
    else:
        print(result%10)