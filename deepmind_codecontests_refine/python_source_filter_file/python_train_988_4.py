withFile = 0

if(withFile == 1):
    fin     = open('input.txt', 'r')
    fout    = open('output.txt', 'w')

def getl():
    if(withFile == 0):
        return input()
    else:
        return fin.readline()
def printl(s):
    if(withFile == 0):
        print(s)
    else:
        fout.write(str(s))
def get_arr():
    x = getl().split(' ')
    if(x[-1] == ''):
        x = x[:-1]
    return list(map(int, x))

n, bx = get_arr()
x = get_arr()
m, by = get_arr()
y = get_arr()

xx = yy = 0
for c in x:
	xx *= bx
	xx += c

for c in y:
	yy *= by
	yy += c

if( xx < yy ):
	printl('<')
elif( xx == yy ):
	printl('=')
else:
	printl('>')

print(xx, yy, sep=' ')

if(withFile == 1):
    fin.close()
    fout.close()