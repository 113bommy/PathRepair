import sys

number_test = int(sys.stdin.readline())

for s in range(number_test):
    x, y ,z = map(int, sys.stdin.readline().split(" "))
    a = max([x,y,z])
    nb = [x,y,z].count(a)
    if nb < 2:
        sys.stdout.write("NO" + "\n")
    elif nb == 3:
        sys.stdout.write("YES" + "\n" + str(a) + " " + str(a) + " " + str(a) + "\n")
    else: 
        sys.stdout.write("YES" + "\n")
        c = 0 
        b = min([x,y,z])
        sys.stdout.write(str(a) + " " + str(b) + " " + str(c) + "\n")



    
    
    

