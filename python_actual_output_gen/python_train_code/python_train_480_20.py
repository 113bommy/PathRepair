T=int(input())
while T>0:
    s=input()
    #print(s[-2:],"heer")
    if(s[-2:]=='po'):
        print("FILLIPINO")
    elif(s[-4:]=='masu' or s[-4:]=='desu'):
        print("JAPANESE")
    elif(s[-5:]=='mnida'):
        print('KOREAN')
    T-=1
