from sys import stdin
def res(di,cad):
    l1="qwertyuiop"
    l2="asdfghjkl;"
    l3="zxcvbnm,./"
    if di== "R":
        for x in cad:
            if x in l1:
                pos=l1.find(x)
                pal=l1[pos-1]
                print(pal,end="")
            elif x in l2:
                pos=l2.find(x)
                pal=l2[pos-1]
                print(pal,end="")
            else:
                pos=l3.find(x)
                pal=l3[pos-1]
                print(pal,end="")
    else:
        for x in cad:
            if x in l1:
                pos=l1.find(x)
                pal=l1[pos+1]
                print(pal,end="")
            elif x in l2:
                pos=l2.find(x)
                pal=l2[pos+1]
                print(pal,end="")
            else:
                pos=l3.find(x)
                pal=l3[pos+1]
                print(pal,end="")
def main():
    d= stdin.readline().strip().upper()
    c= stdin.readline().strip()
    print(res(d,c))
main()
            
        
