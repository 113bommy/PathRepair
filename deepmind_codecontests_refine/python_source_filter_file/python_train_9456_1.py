def a(t,i):
    if i = l - 1:
        if eval(t)==7:
            print(t+"=7")
            exit()
        return
    a(t+"+"+N[i+1],i+1)
    a(t+"-"+N[i+1],i+1)

N = input()
l = len(N)
a(N[0],0)




