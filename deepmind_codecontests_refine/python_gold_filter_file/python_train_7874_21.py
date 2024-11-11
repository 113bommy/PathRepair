a =["great","don't think so","not bad", "don't touch me","cool"]
for i in range(10):
    print(i)
    ans = input()
    if ans!="no":
        if ans in a:
            print("normal")
            exit()
        else:
            print("grumpy")
            exit()