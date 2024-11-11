s=input()
ct=0
if len(s)>0:
    for i in range(len(s)-2):
        p=s[i:i+3]
        #print(p,int(p=='BAC')==1)
        if p=="ABC":
            print("Yes")
            ct+=1
            break
        elif p=="BAC":
            print("Yes")
            ct+=1
            break
        elif p=="CAB":
            print("Yes")
            ct+=1
            break
        elif p=="ACB":
            print("Yes")
            ct+=1
            break
        elif p=="CBA":
            print("Yes")
            ct+=1
            break
        elif p=="BCA":
            print("Yes")
            ct+=1
            break
    if ct==0:
        print("No")