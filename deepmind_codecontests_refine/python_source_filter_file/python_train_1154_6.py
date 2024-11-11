#Stanley Tantysco - 2201814670
#Problem C - Death Note

def day_limit(n):
    if (n >= 1 and n <= 200000):
        return True
    else:
        return False

def page_limit(m):
    if(m >= 1 and m <=1000000000):
        return True
    else:
        return False

def name_limit(a):
    if(a >= 1 and a <= 1000000000):
        return True
    else:
        return False

limit_in=input('Input: ')
parse=limit_in.split(' ')
n=int(parse[0])
m=int(parse[1])

name_in=input()
parse2=name_in.split()

page=[]
namelim=0
numofpage=0
for i in range(0,n):
    namelim += int(parse2[i])
    numofpage=namelim//m
    if numofpage != 0:
        namelim = namelim % m
    page.append(numofpage)
for j in range(0,len(page)):
    print(page[j],end=' ')