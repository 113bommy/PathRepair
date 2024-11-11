a , b =(int(i) for i in input().split())
def mask (l):
    l = str(l)
    con = "0"
    for i in l:
        if i in ["4" , "7"]:
            con+=i
    return int(con)
while True :
    if mask(a+1)==b:
        print(a)
        break
    a+=1
    