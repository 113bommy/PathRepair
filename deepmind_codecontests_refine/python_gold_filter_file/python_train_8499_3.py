for i in map(ord,input()):
    print("..\n.X\n"*(256-i)+".X\n"+"..\n.X\n"*i,end="")
