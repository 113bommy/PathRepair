for n in range(int(input())):
    st=input()
    if(st[-2:-1]=="po"):
        print("FILIPINO")
    elif(st[-4:-1]=="desu" or st[-4:-1]=="masu"):
        print("JAPANESE")
    else:
        print("KOREAN")