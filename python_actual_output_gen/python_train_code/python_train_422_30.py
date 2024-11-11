l=['q','w','e','r','t','y','u','i','o','p',',','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/']
dir=input()
m=input()
for i in m:
    if(dir=="R"):
        print(l[l.index(i)+1],end="")
    else:
        print(l[l.index(i)-1],end="")
    