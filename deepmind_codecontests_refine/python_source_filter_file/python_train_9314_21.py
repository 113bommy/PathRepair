import sys

def pen(x0,y0,x1,y1):
    if float(x0-x1) != 0:
        eme = float( (y1-y0) / (x1-x0) )
        return eme
    else:
        return 'inf'


first_line = 0
ll = set([])

for i in sys.stdin:
    tp = i.split()
    if first_line == 0:
        first_line = 1
        n_trooper = int(tp[0])
        hansolo_position = (int(tp[1]),int(tp[2]))
    else:
        ll.add(pen(int(tp[0]),int(tp[1]),hansolo_position[0],hansolo_position[1]))
        #print (pen(int(tp[0]),int(tp[1]),hansolo_position[0],hansolo_position[1]))
print (ll)
#print (len(ll))
