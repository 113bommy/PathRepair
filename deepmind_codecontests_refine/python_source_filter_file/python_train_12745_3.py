#input
data_out = ""
data_in = input("")
params = data_in.split(" ", 3)
#check input 1
if (len(params) != 3):
    raise Exception("Wrong number of arguments")
totalpages = int(params[0])
currentpage = int(params[1])
navigationsize = int(params[2])
#check input 2
if (totalpages < 3 or totalpages > 100):
    raise Exception("Wrong argument")
if (currentpage < 1 or currentpage > totalpages):
    raise Exception("Wrong argument")
if (navigationsize < 1 or navigationsize > totalpages):
    raise Exception("Wrong argument")
#main code
s = currentpage - navigationsize - 1
e = currentpage + navigationsize
if (s > 1):
    data_out += "<< "
for i in range(s, e):
    page = i+1
    if (page == currentpage):
        data_out += "(%i) " % (page)
    else:
        if (page >= 1 and page <= totalpages):
            data_out += "%i " % (page)
if (e < totalpages):
    data_out += ">>"
#return result
print(data_out.strip())
