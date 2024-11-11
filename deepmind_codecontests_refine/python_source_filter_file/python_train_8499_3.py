for i in map(ord,input()):
    print("..\n.x\n"*(256-i)+".x\n"+"..\n.x\n"*i,end="")
