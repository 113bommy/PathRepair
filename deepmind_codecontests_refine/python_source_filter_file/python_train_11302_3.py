n = int(input())
x,y = [int(i) for i in input().split()]

MIN_B = -10**9
MAX_B = 10**9

l_v = [MIN_B,0]
u_v = [MAX_B,0]
l_h = [MIN_B,0]
u_h = [MAX_B,0]
l_v1  = [MIN_B,MIN_B,0]
u_v1 = [MAX_B,MAX_B,0]
l_v2 = [MIN_B,MAX_B,0]
u_v2 = [MAX_B,MIN_B,0]

chess = []

def ok(type1,x1,y1,x,y):
    if type(type1) is int:
        return False
    if type1 == 'R':
        return x1 == x or y1 == y
    elif type1 == 'B':
        return -x1+y1 == y-x or x1+y1 == x+y
    elif type1 == 'Q':
        return x1 == x or y1 == y or -x1+y1 == y-x or x1+y1 == x+y

for i in range(n):
    t1,t2,t3 = [i for i in input().split()]
    chess.append((t1,int(t2),int(t3)))

for i in chess:
    if i[1] == x: #vertical
        if i[2] > y and i[2] < u_v[0]:
            u_v = [i[2],i[0]]
        if i[2] < y and i[2] > l_v[0]:
            l_v = [i[2],i[0]]
    if i[2] == y: #hori
        if i[1] > x and i[1] < u_h[0]:
            u_h = [i[1],i[0]]
        if i[1] < x and i[1] > l_h[0]:
            l_h = [i[1],i[0]]
    if -i[1] + i[2] == y - x:
        if (i[1] > x and i[2] > y) and (i[1] < u_v1[0] and i[2] < u_v1[1]):
            u_v1 = [i[1],i[2],i[0]]
        if (i[1] < x and i[2] < y) and (i[1] > l_v1[0] and i[2] > l_v1[1]):
            l_v1 = [i[1],i[2],i[0]]
    if i[1] + i[2] == x+y:
        if (i[1] > x and i[2] < y) and (i[1] < u_v2[0] and i[2] > u_v2[1]):
            u_v2 = [i[1],i[2],i[0]]
        if (i[1] < x and i[2] > y) and (i[1] > l_v2[0] and i[2] < l_v2[1]):
            l_v2 = [i[1],i[2],i[0]]

c = False
c = c or ok(l_v[1],x,l_v[0],x,y)
c = c or ok(u_v[1],x,u_v[0],x,y)
c = c or ok(l_h[1],l_h[0],y,x,y)
c = c or ok(u_h[1],u_h[0],y,x,y)
c = c or ok(l_v1[2],l_v1[0],l_v1[1],x,y)
c = c or ok(u_v1[2],u_v1[0],u_v1[1],x,y)
c = c or ok(l_v2[2],l_v2[0],l_v2[1],x,y)
c = c or ok(u_v2[2],u_v2[0],u_v2[1],x,y)

if c:
    print('YES')
else:
    print('NO')


        
    
        
        
        
    
                 
    

