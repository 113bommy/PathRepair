n = input()
k = int(input())
mylist = "None January February March April May June July August September October November December".split(" ")

try :
    if n in mylist : 
        ind = (mylist.index(n) + k) % 12
        res = mylist[ind]
        print(res)
except ValueError :
        print("Error")
