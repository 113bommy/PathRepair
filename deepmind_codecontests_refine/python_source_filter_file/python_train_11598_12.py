n = input()
if n.replace("144","z").replace("14","z").replace("1","z").count("z") == len(n):
    print ("YES")
else:
    print ("NO")
