def a(s,i):
    if i == l-1:
        if eval(s) == 7:
            print(s+"=7")
            exit()
        return
    a(s+"+"+N[i+1],i+1)
    a(s+"-"+N[i+1],i+1)

N = input()
l = len(N)
a(N[0],0)