from sys import stdin
Liste = stdin.read().split("\n")
for i in range(0,int(Liste[0])):
        w = int(Liste[5*i+1].split()[0])
        h = int(Liste[5*i+1].split()[1])
        x = max(int(Liste[5*i+2].split()[-1])-int(Liste[5*i+2].split()[0]),int(Liste[5*i+3].split()[-1])-int(Liste[5*i+3].split()[0]))
        y = max(int(Liste[5*i+4].split()[-1])-int(Liste[5*i+4].split()[0]),int(Liste[5*i+5].split()[-1])-int(Liste[5*i+5].split()[0]))
        print(max(x*h,y*w))
